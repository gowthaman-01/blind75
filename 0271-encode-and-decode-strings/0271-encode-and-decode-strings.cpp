class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        std::string encoded_string = "";

        for (const auto &str: strs) {
            encoded_string.append(std::to_string(str.length()))
                          .append("/") 
                          .append(str);
        }

        return encoded_string;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        size_t pos = 0;
        std::vector<std::string> decoded_strings;

        while (pos < s.length()) {
            size_t slash_pos = s.find("/", pos);
            size_t str_length = std::stoi(s.substr(pos, slash_pos - pos));

            std::string decoded_string = s.substr(slash_pos + 1, str_length);
            decoded_strings.push_back(std::move(decoded_string));

            pos = slash_pos + str_length + 1;
        }

        return decoded_strings;
    }
};



// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));