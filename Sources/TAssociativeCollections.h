//
//  TAssociativeCollections.h
//  Typed
//
//  Created by Martin Kiss on 4.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#pragma mark -
#pragma mark TAssociativeCollection

#define _TAssociativeCollection    id
#define _TAssociativeProtocols     NSObject, NSFastEnumeration, NSCopying, NSMutableCopying, NSSecureCoding

#define TAssociativeGenerate(Key, Value) \
_TDictionaryCreateProtocol(Key, Value) \



#pragma mark -
#pragma mark TDictionary

#define TDictionary(Key, Value)             _TAssociativeCollection<TDictionary_##Key##_##Value>
#define TDictionaryAlloc(Key, Value)        ( (TDictionary(Key, Value)) [NSDictionary alloc] )
#define _TDictionaryForward(Key, Value)     @protocol TDictionary_##Key##_##Value;


