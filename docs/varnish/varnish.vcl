
// Purge will be used from Apache servers.
acl acl_purge {
  "localhost";
  "10.0.0.0"/8;
  "192.0.0.0"/8;
}

sub vcl_recv {
  if (req.restarts == 0) {
    if (req.http.x-forwarded-for) {
      set req.http.X-Forwarded-For =
      req.http.X-Forwarded-For + ", " + client.ip;
    } else {
      set req.http.X-Forwarded-For = client.ip;
    }
  }

  if (req.request == "PURGE" || req.request == "PURGEALL") {
    if (!client.ip ~ acl_purge) {
      // Return error code 405 (Forbidden) when not
      error 405 "Not allowed.";
    }
    if (req.request == "PURGE") {
      // Purge all objects from cache that match the incoming url and host
      ban("req.url == " + req.url + " && req.http.host == " + req.http.host);
    }
    else {
      // Purge all objects from cache that match the incoming host
      ban("req.url ~ ^/ && req.http.host == " + req.http.host);
    }
    // Return a http error code 200 (Ok)
    error 200 "Purged";
  }

  if (req.request != "GET" &&
    req.request != "HEAD" &&
    req.request != "PUT" &&
    req.request != "POST" &&
    req.request != "TRACE" &&
    req.request != "OPTIONS" &&
    req.request != "DELETE") {
      // Non-RFC2616 or CONNECT which is weird.
      return (pipe);
  }

  if (req.request == "POST") {
    // Never cache post requests.
    return (pipe);
  }

  // Use the same cache for every user agent.
  set req.http.user-agent = "Mozilla";
  
  // Normalize accept-encoding header.
  if (req.http.Accept-Encoding) {
    if (req.url ~ "\.(jpg|jpeg|png|gif|gz|tgz|bz2|tbz|mp3|ogg)$") {
      // No point in compressing these
      remove req.http.Accept-Encoding;
    } elsif (req.http.Accept-Encoding ~ "gzip") {
      set req.http.Accept-Encoding = "gzip";
    } elsif (req.http.Accept-Encoding ~ "deflate") {
      set req.http.Accept-Encoding = "deflate";
    } else {
      // Unkown algorithm.
      remove req.http.Accept-Encoding;
    }
  }

  // Ignore cookies not starting with SESS, NO_CACHE or NOCACHE.
  if (req.http.Cookie) {
    set req.http.Cookie = ";" + req.http.Cookie;
    set req.http.Cookie = regsuball(req.http.Cookie, "; +", ";");
    set req.http.Cookie = regsuball(req.http.Cookie, ";(NO_?CACHE|SESS)[^=]+=", "; \1=");
    set req.http.Cookie = regsuball(req.http.Cookie, ";[^ ][^;]*", "");
    set req.http.Cookie = regsuball(req.http.Cookie, "^[; ]+|[; ]+$", "");
    if (req.http.Cookie == "") {
      remove req.http.Cookie;
    }
  }

  return (lookup);
}

sub vcl_pass {
  return (pass);
}

sub vcl_hash {
  hash_data(req.url);
  if (req.http.host) {
    hash_data(req.http.host);
  } else {
    hash_data(server.ip);
  }
  return (hash);
}

sub vcl_fetch {
  if (beresp.http.Set-Cookie) {
    set beresp.ttl = 0s;
    return(hit_for_pass);
  }

  if (req.backend.healthy) {
    set req.grace = 30s;
  } else {
    set req.grace = 6h;
  }

  if (req.url ~ "\.(png|gif|jpg|txt|css|js)$") {
    set beresp.ttl = 20m;
    return(deliver);
  }

  if (req.url ~ "\.php$") {
    set beresp.ttl = 60s;
    return(hit_for_pass);
  }

  if (req.request != "GET" && req.request != "HEAD") {
    set beresp.ttl = 0s;
    return(hit_for_pass);
  }

  if (req.http.Authorization || req.http.Cookie) {
    set beresp.ttl = 0s;
    return(hit_for_pass);
  }

  return(deliver);
}

sub vcl_deliver
{
  if (obj.hits > 0) {
    set resp.http.X-Cache-Hits = obj.hits;
  }
  return(deliver);
}
