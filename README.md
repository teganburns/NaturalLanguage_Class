
# Cloud Natural Language API (C++)
C++ implmentations using Google's Nautral Language API. Checkout Google's [Natual Language API](https://cloud.google.com/natural-language/)
ALL projects use gRPC wich you can checkout at their [Main Website](http://www.grpc.io/) or the [Git Repo](https://github.com/grpc/grpc)

![](https://github.com/teganburns/NaturalLanguage_gRPC/blob/master/docs/media/demonstration.gif?raw=true)

## Overview

gRPC implimentations of Google's "Cloud Natural Language API" in C++.
Documentation overview and more can ber found on [Google's Documentation refrence page](https://cloud.google.com/natural-language/docs/reference/rpc/).


## Usage


### Prerequisites
To use this you need to install and configure the [Google Cloud SDK](https://cloud.google.com/sdk/). The Google cloud SDK handles the authentication process for this, and other Google Cloud APIs.

*Arch Linux:*
``` 
yaourt -S google-cloud-sdk
```

Install and configure [Protocol Buffers (proto3)](https://developers.google.com/protocol-buffers/) along with gRPC. The [Quickstart](http://www.grpc.io/docs/quickstart/cpp.html) section on grpc.io covers the installation/setup process in more detail. 

*Arch Linux*:
```
Note: This installs both gRPC and Proto3. (Thank jeebus!)

yaourt -S grpc
```

### Tweak the code
There are section of the code you may need to change before compileing. These sections should be marked with a comment "TODO". Read the comment on that line and it's corrosponding TODO comment found on the bottom of the page.


### Compile
In order to compile this you will need to use *make*. If you are not fimiliar with Make files then it may be resourceful to do some reserch. 

### Running

To run the program, simply execute it!
```
./natural_language
```


The first prompt will ask what request type you are making. You will need to enter the number corosponding to the request type.
```
---- Request Type ----
        [1] AnalyzeEntities
        [2] AnalyzeSentiment
        [3] AnalyzeSyntax
        [4] AnnotateText
Please select a number...
```

*AnalyzeEntities*:
> "Entity Analysis inspects the given text for known entities (proper nouns such as public figures, landmarks, etc.), and returns information about those entities. Entity analysis is performed with the analyzeEntities method." [Source](https://cloud.google.com/natural-language/docs/analyzing-entities)
    
*AnalizeSentiment*:
> "Sentiment Analysis inspects the given text and identifies the prevailing emotional opinion within the text, especially to determine a writer's attitude as positive, negative, or neutral. Sentiment analysis is performed through the analyzeSentiment method. Currently English, Spanish, and Japanese languages are supported for sentiment analysis." [Source](https://cloud.google.com/natural-language/docs/analyzing-sentiment)
    
*AnalyzeSyntax*:
> "Syntactic Analysis extracts linguistic information, breaking up the given text into a series of sentences and tokens (generally, word boundaries), providing further analysis on those tokens. Syntactic Analysis is performed with the analayzeSyntax method." [Source](https://cloud.google.com/natural-language/docs/analyzing-syntax)
    
*AnnotateText*:
> "The request message for the text annotation API, which can perform multiple analysis types (sentiment, entities, and syntax) in one call." [Source](https://cloud.google.com/natural-language/docs/reference/rpc/google.cloud.language.v1#google.cloud.language.v1.AnnotateTextRequest)

The second prompt will ask for the content or the location of the content.
```
---- Content Type ----
        [1] Local content (file)
        [2] Local content (key input)
        [3] GCS URL (Google Cloud Storage URL)
Please select a number...
```


*Local content (file)*:
> The request content will be a local file. You will need to enter a file path when prompted to do so. 

*Local content (key input)*:
> The request content will be typed by the user when prompted to do so.

*GCS URL (Google Cloud Storage URL)*:
> The request content will be a [Google Cloud Storage URL](https://console.cloud.google.com/storage/). The format is *gs://YOUR_PROJECT* for example *gs://personal_projects/NaturalLanguage.txt*.

*: This can be a word, sentence, maybe paragraph. I've only tested a sentence or two and haven't looked into what the API charter limit is.
    

## Please Note

04/05/2017 - Google's [documentation](https://cloud.google.com/natural-language/docs/reference/rpc/google.cloud.language.v1#google.cloud.language.v1.PartOfSpeech.Case) has a message "PartOfSpeech.Case" while this is a valid variable, "case" is not. Therefore "case" has been changed in the .proto file to "instance".



