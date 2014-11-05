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
_TMutableDictionaryCreateProtocol(Key, Value) \

#define TPair(Key, Value)               _associative[Key] = Value
#define _TAssociativeCollectionMake(MutableType, Key, Value, Pairs...) \
(MutableType(Key, Value))({ \
    MutableType(Key, Value) _associative = [MutableType##Alloc(Key, Value) init];\
    Pairs; \
    _associative; \
})



#pragma mark -
#pragma mark TDictionary

#define TDictionary(Key, Value)                 _TAssociativeCollection<TDictionary_##Key##_##Value>
#define TDictionaryAlloc(Key, Value)            ( (TDictionary(Key, Value)) [NSDictionary alloc] )
#define TDictionaryMake(Key, Value, TPairs...)  ( (TDictionary(Key, Value)) _TAssociativeCollectionMake(TMutableDictionary, Key, Value, TPairs) )
#define _TDictionaryForward(Key, Value)         @protocol TDictionary_##Key##_##Value;



#pragma mark TMutableDictionary

#define TMutableDictionary(Key, Value)                  _TAssociativeCollection<TMutableDictionary_##Key##_##Value>
#define TMutableDictionaryAlloc(Key, Value)             ( (TMutableDictionary(Key, Value)) [NSMutableDictionary alloc] )
#define TMutableDictionaryMake(Key, Value, TPairs...)   _TAssociativeCollectionMake(TMutableDictionary, Key, Value, TPairs)
#define _TMutableDictionaryForward(Key, Value)          @protocol TMutableDictionary_##Key##_##Value;


