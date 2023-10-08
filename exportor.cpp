#include<bits/stdc++.h>
#include<jsoncpp/json/json.h>
#include<curl/curl.h>
using namespace std;


size_t writeFunction(void* ptr, size_t size, size_t nmemb, string* data) {
    data->append((char*)ptr, size * nmemb);
    return size * nmemb;
}
size_t headerWriteFunction(void* ptr, size_t size, size_t nmemb, map<string, string>* data) {
    string header = (char*)ptr;
    int pos = header.find(": ");
    if (pos != string::npos) {
        string key = header.substr(0, pos);
        string value = header.substr(pos + 2, header.size() - pos - 4);
        (*data)[key] = value;
    } return size * nmemb;
}
string geturl(string url, vector<string> header, string data, bool post, map<string, string>& response, bool skipFailed = false, int retryTimes = 5) {
	string method = post ? "POST" : "GET";
    CURL* curl = curl_easy_init();
    if (curl) {
        cout << "Visiting " << method << " " << url << endl;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        if (header.size()) {
            struct curl_slist* headers = NULL;
            for (auto i: header) headers = curl_slist_append(headers, i.c_str());
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        }
        if (post) {
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
            curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, data.size());
        }
        string result = "";
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
        curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, headerWriteFunction);
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, &response);
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            if (retryTimes) {
                cout << curl_easy_strerror(res) << ", " << retryTimes << " times left." << endl;
                return geturl(url, header, data, post, response, skipFailed, retryTimes - 1);
            } curl_easy_cleanup(curl);
            throw runtime_error(curl_easy_strerror(res));
        } int code = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &code);
		if (code != 200 && !skipFailed) {
            if (retryTimes) {
                cout << "Visit " << method << " " << url << ": Failed with code " << code << ", " << retryTimes << " times left." << endl;
                return geturl(url, header, data, post, response, skipFailed, retryTimes - 1);
            } stringstream buffer;
			curl_easy_cleanup(curl);
			buffer << "Visit " << method << " " << url << ": Failed with code " << code << endl;
			buffer << "Info: " << result << endl;
			for (auto v : response) buffer << v.first << ": " << v.second << endl;
			throw runtime_error(buffer.str());
		}
        curl_easy_cleanup(curl);
        return result;
    }
    else throw runtime_error("curl init failed");
}
string easy_geturl(string path) {
    map<string, string> response;
    return geturl(path, {}, "", false, response);
}

string json_encode(Json::Value value) {
    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "";
    builder["emitUTF8"] = true;
    unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    ostringstream os;
    writer->write(value, &os);
    return os.str();
}
string json_pretty_encode(Json::Value value) {
    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "    ";
    builder["emitUTF8"] = true;
    unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    ostringstream os;
    writer->write(value, &os);
    return os.str();
}
Json::Value json_decode(string source) {
    Json::CharReaderBuilder builder;
    builder["collectComments"] = false;
    JSONCPP_STRING errs;
    Json::Value root;
    unique_ptr<Json::CharReader> reader(builder.newCharReader());
    if (!reader->parse(source.c_str(), source.c_str() + source.size(), &root, &errs)) throw runtime_error(errs);
    return root;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " [url] [output]" << endl;
        return 1;
    }
    string url = argv[1], output = argv[2];
    vector<string> dataArr = {"levels", "skins", "backgrounds", "effects", "particles", "engines"};
    Json::Value data;
    for (int i = 0; i < dataArr.size(); i++) {
        int page = json_decode(easy_geturl(url + "/sonolus/" + dataArr[i] + "/list"))["pageCount"].asInt();
        for (int j = 0; j < page; j++) {
            auto res = json_decode(easy_geturl(url + "/sonolus/" + dataArr[i] + "/list?page=" + to_string(j)));
            for (int k = 0; k < res["items"].size(); k++) data[dataArr[i]].append(res["items"][k]);
        }
    }
    ofstream fout(output);
    fout << json_pretty_encode(data);
}
