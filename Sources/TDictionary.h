//
//  TDictionary.h
//  Typed
//
//  Created by Martin Kiss on 5.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TAssociativeCollections.h"



#define _TDictionaryCreateProtocol(Key, Value) \
/*! Types */ \
@class Key, Value; \
/*! NSDictionary Interface */ \
@protocol TDictionary_##Key##_##Value <_TAssociativeProtocols> \
@end


