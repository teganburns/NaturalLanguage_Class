// Author: Tegan Burns-Berger

#ifndef _NATURAL_LANGUAGE_HEADER_
#define _NATURAL_LANGUAGE_HEADER_

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>

#include <grpc++/grpc++.h>
#include "NaturalLanguage.grpc.pb.h"

class NL {

public:

    static std::string SCOPE;
    static bool DEBUG;

    int AnalyzeEntities();
    int AnalyzeSentiment();
    int AnalyzeSyntax();
    int AnnotateText();

protected:

    void read_sentences( const google::protobuf::RepeatedPtrField< google::cloud::language::v1::Sentence >* sentences );
    void read_tokens( const google::protobuf::RepeatedPtrField< google::cloud::language::v1::Token >* tokens );
    void read_entity( const google::protobuf::RepeatedPtrField< google::cloud::language::v1::Entity >* entities );
    void read_sentiment( const google::cloud::language::v1::Sentiment* document_sentiment );
    void read_language( const std::string* lang );
    bool set_document( google::cloud::language::v1::Document* doc );

};



#endif
