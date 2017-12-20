//
// Created by U203872 on 12/20/17.
//

#ifndef GOOGLE_TEST_DEMO_HTTPFETCH_H
#define GOOGLE_TEST_DEMO_HTTPFETCH_H


#include <string>

class HttpFetch {
public:

    virtual ~HttpFetch( ) {

    }

    virtual std::string getUrlContentAsString( const std::string &url ) const;
};

#endif //GOOGLE_TEST_DEMO_HTTPFETCH_H
