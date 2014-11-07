//
//  TAssociativeCollections.h
//  Typed
//
//  Created by Martin Kiss on 4.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#pragma mark -
#pragma mark TAssociativeCollection

#define _TAssociativeProtocols     NSObject, NSFastEnumeration, NSCopying, NSMutableCopying, NSSecureCoding

#define TAssociativeGenerate(Key, Value) \
_TDictionaryCreateProtocol(Key, Value) \
_TMutableDictionaryCreateProtocol(Key, Value) \
_TCacheCreateProtocol(Key, Value) \

#define TPair(Key, Value)               [_associative setObject:(Value) forKey:(Key)]
#define _TAssociativeCollectionMake(MutableType, Key, Value, Pairs...) \
(MutableType(Key, Value))({ \
    MutableType(Key, Value) _associative = [MutableType##Alloc(Key, Value) init];\
    Pairs; \
    _associative; \
})



#pragma mark -
#pragma mark TDictionary

#define TDictionary(Key, Value)                 Key##To##Value##Dictionary
#define TDictionaryAlloc(Key, Value)            ( (TDictionary(Key, Value)) [NSDictionary alloc] )
#define TDictionaryMake(Key, Value, TPairs...)  ( (TDictionary(Key, Value)) _TAssociativeCollectionMake(TMutableDictionary, Key, Value, TPairs) )
#define _TDictionaryForward(Key, Value) \
    @protocol TDictionary_##Key##_##Value; \
    typedef id<TDictionary_##Key##_##Value> Key##To##Value##Dictionary; \



#pragma mark TMutableDictionary

#define TMutableDictionary(Key, Value)                  Key##To##Value##MutableDictionary
#define TMutableDictionaryAlloc(Key, Value)             ( (TMutableDictionary(Key, Value)) [NSMutableDictionary alloc] )
#define TMutableDictionaryMake(Key, Value, TPairs...)   _TAssociativeCollectionMake(TMutableDictionary, Key, Value, TPairs)
#define _TMutableDictionaryForward(Key, Value) \
    @protocol TMutableDictionary_##Key##_##Value; \
    typedef id<TMutableDictionary_##Key##_##Value> Key##To##Value##MutableDictionary; \



#pragma mark - TCache

#define TCache(Key, Value)                  Key##To##Value##Cache
#define TCacheAlloc(Key, Value)             ( (TCache(Key, Value)) [NSCache alloc] )
#define TCacheMake(Key, Value, TPairs...)   _TAssociativeCollectionMake(TCache, Key, Value, TPairs)
#define _TCacheForward(Key, Value) \
    @protocol TCache_##Key##_##Value; \
    typedef id<TCache_##Key##_##Value> Key##To##Value##Cache; \


