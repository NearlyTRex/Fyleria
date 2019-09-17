-- Configuration
libSoup_extradir = "Libs/Soup/extra/"
libSoup_origdir = "Libs/Soup/orig/"
libSoup_srcdir = libSoup_origdir .. "libsoup/"
libSoup_incdir = libSoup_origdir

-- Includes
libSoup_includedirs = {
    libSoup_incdir,
    libSoup_extradir,
    libSoup_extradir .. "libsoup/"
}
if os.host() == "linux" then
    table.insert(libSoup_includedirs, libSoup_extradir .. "linux/")
end

-- Defines
libSoup_defines = {
    "_FILE_OFFSET_BITS=64",
    "_DEFAULT_SOURCE",
    "HAVE_CONFIG_H",
    "LIBSOUP_COMPILATION"
}
libSoup_debugdefines = {
}
libSoup_releasedefines = {
}

-- Options
libSoup_buildoptions = {
    "-fvisibility=hidden"
}
libSoup_linkoptions = {
}

-- Libs
libSoup_libs = {
}

-- Sources
libSoup_sources = {
    libSoup_srcdir .. "soup-address.c",
    libSoup_srcdir .. "soup-auth.c",
    libSoup_srcdir .. "soup-auth-basic.c",
    libSoup_srcdir .. "soup-auth-digest.c",
    libSoup_srcdir .. "soup-auth-ntlm.c",
    libSoup_srcdir .. "soup-auth-negotiate.c",
    libSoup_srcdir .. "soup-auth-domain.c",
    libSoup_srcdir .. "soup-auth-domain-basic.c",
    libSoup_srcdir .. "soup-auth-domain-digest.c",
    libSoup_srcdir .. "soup-auth-manager.c",
    libSoup_srcdir .. "soup-body-input-stream.c",
    libSoup_srcdir .. "soup-body-output-stream.c",
    libSoup_srcdir .. "soup-cache.c",
    libSoup_srcdir .. "soup-cache-client-input-stream.c",
    libSoup_srcdir .. "soup-cache-input-stream.c",
    libSoup_srcdir .. "soup-client-input-stream.c",
    libSoup_srcdir .. "soup-connection.c",
    libSoup_srcdir .. "soup-connection-auth.c",
    libSoup_srcdir .. "soup-content-decoder.c",
    libSoup_srcdir .. "soup-content-processor.c",
    libSoup_srcdir .. "soup-content-sniffer.c",
    libSoup_srcdir .. "soup-content-sniffer-stream.c",
    libSoup_srcdir .. "soup-converter-wrapper.c",
    libSoup_srcdir .. "soup-cookie.c",
    libSoup_srcdir .. "soup-cookie-jar.c",
    libSoup_srcdir .. "soup-cookie-jar-db.c",
    libSoup_srcdir .. "soup-cookie-jar-text.c",
    libSoup_srcdir .. "soup-date.c",
    libSoup_srcdir .. "soup-directory-input-stream.c",
    libSoup_srcdir .. "soup-filter-input-stream.c",
    libSoup_srcdir .. "soup-form.c",
    libSoup_srcdir .. "soup-hsts-enforcer.c",
    libSoup_srcdir .. "soup-hsts-enforcer-db.c",
    libSoup_srcdir .. "soup-hsts-policy.c",
    libSoup_srcdir .. "soup-headers.c",
    libSoup_srcdir .. "soup-init.c",
    libSoup_srcdir .. "soup-io-stream.c",
    libSoup_srcdir .. "soup-logger.c",
    libSoup_srcdir .. "soup-message.c",
    libSoup_srcdir .. "soup-message-body.c",
    libSoup_srcdir .. "soup-message-client-io.c",
    libSoup_srcdir .. "soup-message-headers.c",
    libSoup_srcdir .. "soup-message-io.c",
    libSoup_srcdir .. "soup-message-queue.c",
    libSoup_srcdir .. "soup-message-server-io.c",
    libSoup_srcdir .. "soup-method.c",
    libSoup_srcdir .. "soup-misc.c",
    libSoup_srcdir .. "soup-multipart.c",
    libSoup_srcdir .. "soup-multipart-input-stream.c",
    libSoup_srcdir .. "soup-password-manager.c",
    libSoup_srcdir .. "soup-path-map.c",
    libSoup_srcdir .. "soup-proxy-resolver.c",
    libSoup_srcdir .. "soup-proxy-resolver-default.c",
    libSoup_srcdir .. "soup-proxy-resolver-wrapper.c",
    libSoup_srcdir .. "soup-proxy-uri-resolver.c",
    libSoup_srcdir .. "soup-request.c",
    libSoup_srcdir .. "soup-request-data.c",
    libSoup_srcdir .. "soup-request-file.c",
    libSoup_srcdir .. "soup-request-http.c",
    libSoup_srcdir .. "soup-requester.c",
    libSoup_srcdir .. "soup-server.c",
    libSoup_srcdir .. "soup-session.c",
    libSoup_srcdir .. "soup-session-async.c",
    libSoup_srcdir .. "soup-session-feature.c",
    libSoup_srcdir .. "soup-session-sync.c",
    libSoup_srcdir .. "soup-socket.c",
    libSoup_srcdir .. "soup-socket-properties.c",
    libSoup_srcdir .. "soup-status.c",
    libSoup_srcdir .. "soup-tld.c",
    libSoup_srcdir .. "soup-uri.c",
    libSoup_srcdir .. "soup-value-utils.c",
    libSoup_srcdir .. "soup-version.c",
    libSoup_srcdir .. "soup-websocket.c",
    libSoup_srcdir .. "soup-websocket-connection.c",
    libSoup_srcdir .. "soup-websocket-extension.c",
    libSoup_srcdir .. "soup-websocket-extension-deflate.c",
    libSoup_srcdir .. "soup-websocket-extension-manager.c",
    libSoup_srcdir .. "soup-xmlrpc.c",
    libSoup_srcdir .. "soup-xmlrpc-old.c",
    libSoup_extradir .. "libsoup/soup-enum-types.c"
}
