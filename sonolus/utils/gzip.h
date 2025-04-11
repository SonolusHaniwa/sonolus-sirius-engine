#ifndef GZIP_H
#define GZIP_H
#include<zlib.h>

#define MOD_GZIP_ZLIB_WINDOWSIZE 15
#define MOD_GZIP_ZLIB_CFACTOR    9
#define MOD_GZIP_ZLIB_BSIZE      8096

string compress_gzip(string str, int compressionlevel = Z_BEST_COMPRESSION) {
    z_stream zs;
    memset(&zs, 0, sizeof(zs));
    if (deflateInit2(&zs, 
        compressionlevel,
        Z_DEFLATED,
        MOD_GZIP_ZLIB_WINDOWSIZE + 16, 
        MOD_GZIP_ZLIB_CFACTOR,
        Z_DEFAULT_STRATEGY) != Z_OK
    ) throw(runtime_error("deflateInit2 failed while compressing."));
    char* x = const_cast<char*>(str.c_str());
    zs.next_in = (Bytef*)x;
    zs.avail_in = str.size();
    int ret;
    char outbuffer[32768];
    string outstring;
    while(true) {
        zs.next_out = reinterpret_cast<Bytef*>(outbuffer);
        zs.avail_out = sizeof(outbuffer);
        ret = deflate(&zs, Z_FINISH);
        if (outstring.size() < zs.total_out) outstring.append(outbuffer, zs.total_out - outstring.size());
        if (ret != Z_OK) break;
    }
    deflateEnd(&zs);
    if (ret != Z_STREAM_END) {
        ostringstream oss;
        oss << "Exception during zlib compression: (" << ret << ") " << zs.msg;
        throw(runtime_error(oss.str()));
    }
    return outstring;
}

string compress_deflate(string str, int compressionlevel = Z_BEST_COMPRESSION) {
    z_stream zs;
    memset(&zs, 0, sizeof(zs));
    if (deflateInit(&zs, compressionlevel) != Z_OK)
        throw(runtime_error("deflateInit failed while compressing."));
    zs.next_in = (Bytef*)str.c_str();
    zs.avail_in = str.size();
    int ret;
    char outbuffer[32768];
    string outstring;
    while(true) {
        zs.next_out = reinterpret_cast<Bytef*>(outbuffer);
        zs.avail_out = sizeof(outbuffer);
        ret = deflate(&zs, Z_FINISH);
        if (outstring.size() < zs.total_out)
            outstring.append(outbuffer, zs.total_out - outstring.size());
        if (ret != Z_OK) break;
    } 
    deflateEnd(&zs);
    if (ret != Z_STREAM_END) {
        ostringstream oss;
        oss << "Exception during zlib compression: (" << ret << ") " << zs.msg;
        throw(runtime_error(oss.str()));
    }
	return outstring;
}

string decompress_deflate(string str) {
    z_stream zs;
    memset(&zs, 0, sizeof(zs));
    if (inflateInit(&zs) != Z_OK)
        throw(runtime_error("inflateInit failed while decompressing."));
    zs.next_in = (Bytef*)str.c_str();
    zs.avail_in = str.size();
    int ret;
    char outbuffer[32768];
    string outstring;
    while(true) {
        zs.next_out = reinterpret_cast<Bytef*>(outbuffer);
        zs.avail_out = sizeof(outbuffer);
        ret = inflate(&zs, 0);
        if (outstring.size() < zs.total_out)
            outstring.append(outbuffer, zs.total_out - outstring.size());
        if (ret != Z_OK) break;
    }
    inflateEnd(&zs);
    if (ret != Z_STREAM_END) {
        ostringstream oss;
        oss << "Exception during zlib decompression: (" << ret << ") " << zs.msg;
        throw(runtime_error(oss.str()));
    }
    return outstring;
}

string decompress_gzip(string str) {
    z_stream zs;
    memset(&zs, 0, sizeof(zs));
    if (inflateInit2(&zs, MOD_GZIP_ZLIB_WINDOWSIZE + 16) != Z_OK)
        throw(runtime_error("inflateInit failed while decompressing."));
    char* x = const_cast<char*>(str.c_str());
    zs.next_in = (Bytef*)x;
    zs.avail_in = str.size();
    int ret;
    char outbuffer[100010];
    string outstring;
    while (true) {
        zs.next_out = reinterpret_cast<Bytef*>(outbuffer);
        zs.avail_out = sizeof(outbuffer);
        ret = inflate(&zs, 0);
        if (outstring.size() < zs.total_out)
            outstring.append(outbuffer, zs.total_out - outstring.size());
        if (ret != Z_OK) break;
    }
    inflateEnd(&zs);
    if (ret != Z_STREAM_END) {
        ostringstream oss;
        oss << "Exception during zlib decompression: (" << ret << ") " << zs.msg;
        throw(runtime_error(oss.str()));
    }
    return outstring;
}

#endif
