#include "natural_language.h"
#include <iostream>
#include <ctime>

int main (){

    system("clear");

    //std::cout << "Time: " << std::time(0) << std::endl;

    NL Lang;

    int request_type;

    std::cout
        << "---- Request Type ----"
        << "\n\t[1] AnalyzeEntities"
        << "\n\t[2] AnalyzeSentiment"
        << "\n\t[3] AnalyzeSyntax"
        << "\n\t[4] AnnotateText"
        << "\nPlease select a number...";

    std::cin >> request_type;

    switch ( request_type ) {
        case 1:
            Lang.AnalyzeEntities();
            break;
        case 2:
            Lang.AnalyzeSentiment();
            break;
        case 3:
            Lang.AnalyzeSyntax();
            break;
        case 4:
            Lang.AnnotateText();
            break;
        default:
            std::cout << "Selection \"" << request_type << "\" is not valid." << std::endl;
            std::exit( EXIT_FAILURE );
            break;
    
    } 

    std::cout << "\nAll Finished!" << std::endl;

    return 0;
}









