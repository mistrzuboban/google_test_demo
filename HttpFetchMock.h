//
// Created by U203872 on 12/20/17.
//

#ifndef GOOGLE_TEST_DEMO_HTTPFETCHMOCK_H
#define GOOGLE_TEST_DEMO_HTTPFETCHMOCK_H

#include <gmock/gmock-generated-function-mockers.h>
#include "HttpFetch.h"


class HttpFetchMock : public HttpFetch {
public:
    MOCK_CONST_METHOD1( getUrlContentAsString, std::string( const std::string& ) );
};


#endif //GOOGLE_TEST_DEMO_HTTPFETCHMOCK_H
