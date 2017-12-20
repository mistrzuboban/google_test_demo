//
// Created by U203872 on 12/20/17.
//

#ifndef GOOGLE_TEST_DEMO_HTMLPARSER_H
#define GOOGLE_TEST_DEMO_HTMLPARSER_H

#include <string>
#include <vector>
#include "HttpFetch.h"

class HtmlParser {
public:

    HtmlParser( const HttpFetch &http ) : m_http( http ) {

    }

    std::vector<std::string> getAllLinks( const std::string &url ) const;
private:
    const HttpFetch& m_http;
};


#endif //GOOGLE_TEST_DEMO_HTMLPARSER_H
