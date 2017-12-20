//
// Created by U203872 on 12/20/17.
//

#include "HtmlParser.h"


std::vector<std::string> HtmlParser::getAllLinks( const std::string &url ) const {
    // TODO
    auto vec = std::vector<std::string>();
    vec.push_back(m_http.getUrlContentAsString(url));
    return vec;
}