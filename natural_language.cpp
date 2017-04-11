// Author: Tegan Burns-Berger

#include "natural_language.h"

// -------------------- //

std::string NL::SCOPE = "language.googleapis.com";
bool NL::DEBUG = false;

// -------------------- //

int NL::AnalyzeEntities () {
    
    using namespace google::cloud::language::v1;
    

    std::cout << "\n\n------AnalyzeEntities------" << std::endl;

    // Init Objects //
    std::cout << "Init Objects...";
    AnalyzeEntitiesRequest request;
    Document *document;
    EncodingType encoding_type;
    AnalyzeEntitiesResponse response;
    grpc::Status status;
    grpc::ClientContext context;
    std::cout << "Done!" << std::endl;
    
    // Document //
    set_document( request.mutable_document() ) ? (void)0 : std::exit( EXIT_FAILURE ) ;
    
    // EncodingType // 
    std::cout << "Setting Encoding...";
    request.set_encoding_type( EncodingType::UTF8 );
    std::cout << "Done!" << std::endl;

    // Send Request //
    auto creds = grpc::GoogleDefaultCredentials();
    auto channel = grpc::CreateChannel( SCOPE, creds );
    std::unique_ptr< LanguageService::Stub> stub( LanguageService::NewStub( channel ) );
    status = stub->AnalyzeEntities( &context, request, &response );

    // Response //
    std::cout << "status.ok(): " << status.ok() << std::endl;

    if ( status.ok() ) {
        std::cout << "\n\n------Response------" << std::endl << std::endl;
        std::cout << "Status returned OK" << std::endl;

        read_entity( &response.entities()  );
        read_language( &response.language() );

    } else if ( status.ok() ){
        std::cout << "Status Returned Canceled" << std::endl;

    }else {
        std::cout << "gRPC Status Error Code: " << status.error_code() << "\ngRPC Status Error Message: " << status.error_message() << std::endl;
        std::cerr << "RPC failed" << std::endl;;
        return -1;
    }


    return 0;

}

int NL::AnalyzeSentiment () {
    
    using namespace google::cloud::language::v1;



    std::cout << "\n\n------AnalyzeSentiment------" << std::endl;

    // Init Objects //
    std::cout << "Init Objects...";
    AnalyzeSentimentRequest request;
    Document *document;
    EncodingType encoding_type;
    AnalyzeSentimentResponse response;
    grpc::Status status;
    grpc::ClientContext context;
    std::cout << "Done!" << std::endl;

    // Document //
    set_document( request.mutable_document() ) ? (void)0 : std::exit( EXIT_FAILURE ) ;
    
    // EncodingType // 
    std::cout << "Setting Encoding...";
    request.set_encoding_type( EncodingType::UTF8 );
    std::cout << "Done!" << std::endl;

    // Send Request //
    auto creds = grpc::GoogleDefaultCredentials();
    auto channel = grpc::CreateChannel( SCOPE, creds );
    std::unique_ptr< LanguageService::Stub> stub( LanguageService::NewStub( channel ) );
    status = stub->AnalyzeSentiment( &context, request, &response );


    // Response //
    std::cout << "status.ok(): " << status.ok() << std::endl;

    if ( status.ok() ) {
        std::cout << "\n\n------Response------" << std::endl << std::endl;
        std::cout << "Status returned OK" << std::endl;

        read_sentences( &response.sentences() );
        if ( response.has_document_sentiment() )
            read_sentiment( &response.document_sentiment() ) ;
        read_language( &response.language() );

    } else if ( status.ok() ){
        std::cout << "Status Returned Canceled" << std::endl;

    }else {
        std::cout << "gRPC Status Error Code: " << status.error_code() << "\ngRPC Status Error Message: " << status.error_message() << std::endl;
        std::cerr << "RPC failed" << std::endl;;
        return -1;
    }


    return 0;

}

int NL::AnalyzeSyntax () {
    
    using namespace google::cloud::language::v1;



    std::cout << "\n\n------AnalyzeSyntax------" << std::endl;

    // Init Objects //
    std::cout << "Init Objects...";
    AnalyzeSyntaxRequest request;
    Document *document;
    EncodingType encoding_type;
    AnalyzeSyntaxResponse response;
    grpc::Status status;
    grpc::ClientContext context;
    std::cout << "Done!" << std::endl;
    
    // Document //
    set_document( request.mutable_document() ) ? (void)0 : std::exit( EXIT_FAILURE ) ;
    
    // EncodingType // 
    std::cout << "Setting Encoding...";
    request.set_encoding_type( EncodingType::UTF8 );
    std::cout << "Done!" << std::endl;

    // Send Request //
    auto creds = grpc::GoogleDefaultCredentials();
    auto channel = grpc::CreateChannel( SCOPE, creds );
    std::unique_ptr< LanguageService::Stub> stub( LanguageService::NewStub( channel ) );
    status = stub->AnalyzeSyntax( &context, request, &response );

    // Response //
    std::cout << "status.ok(): " << status.ok() << std::endl;

    if ( status.ok() ) {
        std::cout << "\n\n------Response------" << std::endl << std::endl;
        std::cout << "Status returned OK" << std::endl;

        read_sentences( &response.sentences() );
        read_tokens( &response.tokens() );
        read_language( &response.language() );

    } else if ( status.ok() ){
        std::cout << "Status Returned Canceled" << std::endl;

    }else {
        std::cout << "gRPC Status Error Code: " << status.error_code() << "\ngRPC Status Error Message: " << status.error_message() << std::endl;
        std::cerr << "RPC failed" << std::endl;;
        return -1;
    }


    return 0;
}

int NL::AnnotateText () {
    
    using namespace google::cloud::language::v1;


    std::cout << "\n\n------AnnotateText------" << std::endl;

    // Init Objects //
    std::cout << "Init Objects...";
    AnnotateTextRequest request;
    Document *document;
    AnnotateTextRequest_Features *features;
    EncodingType encoding_type;
    AnnotateTextResponse response;
    grpc::Status status;
    grpc::ClientContext context;
    std::cout << "Done!" << std::endl;

    // Document //
    set_document( request.mutable_document() ) ? (void)0 : std::exit( EXIT_FAILURE ) ;
     
    // Features //
    std::cout << "Setting Features...";
    features = request.mutable_features();
    features->set_extract_syntax( 1 );
    features->set_extract_entities( 1 );
    features->set_extract_document_sentiment( 1 );
    std::cout << "Done!" << std::endl;

    // EncodingType //
    std::cout << "Setting Encoding...";
    request.set_encoding_type( EncodingType::UTF8 );
    std::cout << "Done!" << std::endl;

    // Send Request //
    auto creds = grpc::GoogleDefaultCredentials();
    auto channel = grpc::CreateChannel( SCOPE, creds );
    std::unique_ptr< LanguageService::Stub> stub( LanguageService::NewStub( channel ) );
    status = stub->AnnotateText( &context, request, &response );

    // AnnotateText Response //
    std::cout << "status.ok(): " << status.ok() << std::endl;

    if ( status.ok() ) {
        std::cout << "\n\n------Response------" << std::endl << std::endl;
        std::cout << "Status returned OK" << std::endl;

        read_sentences( &response.sentences() );
        read_tokens( &response.tokens() );
        read_entity( &response.entities()  );
        if ( response.has_document_sentiment() )
            read_sentiment( &response.document_sentiment() ) ;
        read_language( &response.language() );

    } else if ( status.ok() ){
        std::cout << "Status Returned Canceled" << std::endl;

    }else {
        std::cout << "gRPC Status Error Code: " << status.error_code() << "\ngRPC Status Error Message: " << status.error_message() << std::endl;
        std::cerr << "RPC failed" << std::endl;;
        return -1;
    }


    return 0;

}


void NL::read_sentences( const google::protobuf::RepeatedPtrField< google::cloud::language::v1::Sentence >* sentences ) {
    
    using namespace google::cloud::language::v1;


        // SENTENCES //
        std::cout << "----Sentences----" << std::endl;
        std::cout << "Sentences Size: " << sentences->size() << std::endl;
        for( int i = 0; i < sentences->size(); i++ ) {
            std::cout << "Sentence " << i << " has text: " << sentences->Get( i ).has_text() << std::endl;
            if ( sentences->Get( i ).has_text() ) {
                std::cout << "\tSentence text: " << sentences->Get( i ).text().content() << std::endl;
            }

            std::cout << "Sentence " << i << " has sentiment: " << sentences->Get( i ).has_sentiment() << std::endl;
            if ( sentences->Get( i ).has_text() ) {
                std::cout << "\tSentence " << i << " sentiment: "
                    << "\n\t\tMagnitude: "
                    << sentences->Get( i ).sentiment().magnitude() // float
                    << "\n\t\tScore: "
                    << sentences->Get( i ).sentiment().score() // float
                    << std::endl;
            }

        }

}

void NL::read_tokens( const google::protobuf::RepeatedPtrField< google::cloud::language::v1::Token >* tokens ) {
    
    using namespace google::cloud::language::v1;



        // TOKENS //
        std::cout << "\n----Tokens----" << std::endl;
        std::cout << "Tokens Size: " << tokens->size() << std::endl;
        for ( int i = 0; i < tokens->size(); i++ ) {
           
            std::cout
                << "-- Token " << i << " --"
                << std::endl;

            std::cout
                << "Token " << i << " has text: " 
                << tokens->Get( i ).has_text() 
                << std::endl;

            if ( tokens->Get( i ).has_text() ) {
                std::cout
                    << "\tToken " << i << " text: " 
                    << tokens->Get( i ).text().content() // string
                    << "\n\tScore: "
                    << tokens->Get( i ).text().begin_offset() // int32 
                    << std::endl;
            }

            std::cout
                << "Token " << i << " has PartOfSpeech: " 
                << tokens->Get( i ).has_part_of_speech() 
                << std::endl;

            if ( tokens->Get( i ).has_part_of_speech() ) {
                std::cout
                    << "\tToken " << i << " PartOfSpeech: "
                    << "\n\t\tAspect: "
                    << PartOfSpeech_Aspect_Name( tokens->Get( i ).part_of_speech().aspect() )
                    << "\n\t\tCase: "
                    << PartOfSpeech_Case_Name( tokens->Get( i ).part_of_speech().instance() )
                    << "\n\t\tForm: "
                    << PartOfSpeech_Form_Name( tokens->Get( i ).part_of_speech().form() )
                    << "\n\t\tGender: "
                    << PartOfSpeech_Gender_Name( tokens->Get( i ).part_of_speech().gender() )
                    << "\n\t\tMood: "
                    << PartOfSpeech_Mood_Name( tokens->Get( i ).part_of_speech().mood() )
                    << "\n\t\tNumber: "
                    << PartOfSpeech_Number_Name( tokens->Get( i ).part_of_speech().number() )
                    << "\n\t\tPerson: "
                    << PartOfSpeech_Person_Name( tokens->Get( i ).part_of_speech().person() )
                    << "\n\t\tProper: "
                    << PartOfSpeech_Proper_Name( tokens->Get( i ).part_of_speech().proper() )
                    << "\n\t\tReciprocity: "
                    << PartOfSpeech_Reciprocity_Name( tokens->Get( i ).part_of_speech().reciprocity() )
                    << "\n\t\tTag: "
                    << PartOfSpeech_Tag_Name( tokens->Get( i ).part_of_speech().tag() )
                    << "\n\t\tTense: "
                    << PartOfSpeech_Tense_Name( tokens->Get( i ).part_of_speech().tense() )
                    << "\n\t\tVoice: "
                    << PartOfSpeech_Voice_Name( tokens->Get( i ).part_of_speech().voice() )


                    << std::endl;
            
            }
        
            std::cout
                << "Token " << i << " has DependencyEdge: "
                << tokens->Get( i ).has_dependency_edge()
                << std::endl;

            if ( tokens->Get( i ).has_dependency_edge() ) {
                std::cout
                    << "\tToken " << i << " DependencyEdge: "
                    << "\n\t\tHead Token Index: "
                    << tokens->Get( i ).dependency_edge().head_token_index() // int32
                    << "\n\t\tLabel: "
                    << DependencyEdge_Label_Name( tokens->Get( i ).dependency_edge().label() )
                    << std::endl;
            
            }

            std::cout
                << "Token " << i << " lemma: "
                << tokens->Get( i ).lemma() // string
                << std::endl
                << std::endl;

        }

}

void NL::read_entity( const google::protobuf::RepeatedPtrField< google::cloud::language::v1::Entity >* entities ) {
    
    using namespace google::cloud::language::v1;


        // ENTITIES //
        std::cout << "\n----Entities----" << std::endl;
        std::cout << "Entities Size: " << entities->size() << std::endl;
        for ( int i = 0; i < entities->size(); i++ ) {
            std::cout << "Entity " << i << " name: " << entities->Get( i ).name() << std::endl;
            
            std::cout
                << "Entity Type: "
                << Entity_Type_Name( entities->Get( i ).type() )
                << std::endl;

            for ( int j = 0; j < entities->Get( i ).metadata_size(); j++ ) {
                //response.entities->Get( i ).metadata( j ) // ::google::protobuf::Map // TODO: [METADATA_MAP] //
            }
            
            std::cout
                << "Salience: "
                << entities->Get( i ).salience() // float
                << std::endl;

            for ( int j = 0; j < entities->Get( i ).mentions_size(); j++ ) {
                
                std::cout
                    << "Entity Mention " << j << " has text: "
                    << entities->Get( i ).mentions( j ).has_text()
                    << std::endl;

                if ( entities->Get( i ).mentions( j ).has_text() ) {
                    std::cout
                        << "\tEntity Mention " << j << " text content: "
                        << entities->Get( i ).mentions( j ).text().content()
                        << "\n\tEntity Mention " << j << " text begin offset: "
                        << entities->Get( i ).mentions( j ).text().begin_offset()
                        << "\n\tEntity Mention " << j << " type: "
                        << EntityMention_Type_Name( entities->Get( i ).mentions( j ).type() )
                        << std::endl;
                }
            }
        }


}

void NL::read_sentiment( const google::cloud::language::v1::Sentiment* document_sentiment ) {
    
    using namespace google::cloud::language::v1;

    // SENTIMENT /
    std::cout << "\n----Sentiment----" << std::endl;
    //std::cout << "Has Document Sentiment: " << has_document_sentiment() << std::endl;
    
    std::cout
        << "Document Sentiment magnitude: "
        << document_sentiment->magnitude()
        << "\nDocument Sentiment score: "
        << document_sentiment->magnitude()
        << std::endl;
}

void NL::read_language( const std::string* lang ) {
    
    using namespace google::cloud::language::v1;



        // LANGUAGE //
        std::cout << "\n----Language----" << std::endl;
        std::cout << "Language: " << *lang << std::endl;

}

bool NL::set_document( google::cloud::language::v1::Document* doc ) {

    using namespace google::cloud::language::v1;


    int content_type;
    std::string content, content_file;
    std::fstream file;
    char content_c[256];
    std::string name;
    std::stringstream content_buffer;

    system("clear");

    std::cout
        << "---- Content Type ---- "
        << "\n\t[1] Local content (file)"
        << "\n\t[2] Local content (key input)"
        << "\n\t[3] GCS URL (Google Cloud Storage URL)"
        << "\nPlease select a number...";

    std::cin >> content_type;

    switch ( content_type ) {
        case 1:
            // Get string input of file path //
            doc->set_type( Document_Type::Document_Type_PLAIN_TEXT );
            std::cout << "Please enter the file to be analyzed: ";
            std::cin >> content_file;
            file.open( content_file, std::ios::in);
            content_buffer << file.rdbuf();
            file.close();
            doc->set_content( content_buffer.str() );
            break;
        case 2:
            // Local Content //
            doc->set_type( Document_Type::Document_Type_PLAIN_TEXT );
            std::cout << "\nPlease enter the text to be analyzed: ";
            std::cin.ignore( 1 , '\n');
            std::getline(std::cin, content, '\n' );
            std::cout << "\nYou typed: " << content << std::endl;
            doc->set_content( content );
            break;
        case 3:
            // gcs uri //
            doc->set_type( Document_Type::Document_Type_HTML ); 
            std::cout << "\nPlease enter the gcs content uri: ";
            std::cin >> content;
            doc->set_gcs_content_uri( content );
            break;
        default:
            std::cerr << "Selection \"" << content_type << "\" is not valid." << std::endl;
            return false;
            break;
    
    }

    return true;
}



// TODO: [METADATA_MAP] Finish reading this back. //
//
