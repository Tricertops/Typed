//
//  TMutableDictionary.h
//  Typed
//
//  Created by Martin Kiss on 5.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TDictionary.h"


#define _TMutableDictionaryCreateProtocol(Key,KPtr, Value,VPtr) \
/*! Types */ \
_TArrayForward(Key) \
/*! NSMutableDictionary Interface */ \
_TMutableDictionaryForward(Key, Value); \
@protocol TMutableDictionary_##Key##_##Value <TDictionary_##Key##_##Value> \
- (TMutableDictionary(Key, Value))self; \
- (NSMutableDictionary *)untyped; \
/*! Initializing a Dictionary */ \
- (TMutableDictionary(Key, Value))initWithDictionary:(TDictionary(Key, Value))other; \
- (TMutableDictionary(Key, Value))initWithDictionary:(TDictionary(Key, Value))other copyItems:(BOOL)flag; \
- (TMutableDictionary(Key, Value))initWithObjects:(TArray(Value))objects forKeys:(TArray(Key))keys; \
- (TMutableDictionary(Key, Value))initWithObjects:(const Value VPtr __autoreleasing [])objects forKeys:(const Key<NSCopying> KPtr __autoreleasing [])keys count:(NSUInteger)count; \
- (TMutableDictionary(Key, Value))initWithObjectsAndKeys:(Value VPtr)firstObject, ... NS_REQUIRES_NIL_TERMINATION; \
- (TMutableDictionary(Key, Value))initWithContentsOfFile:(NSString *)path; \
- (TMutableDictionary(Key, Value))initWithContentsOfURL:(NSURL *)url; \
- (TMutableDictionary(Key, Value))init; \
- (TMutableDictionary(Key, Value))initWithCoder:(NSCoder *)decoder; \
- (TMutableDictionary(Key, Value))initWithCapacity:(NSUInteger)capacity; \
/*! Adding & Replacing Entries */ \
- (void)setObject:(Value VPtr)anObject forKey:(Key<NSCopying> KPtr)key; \
- (void)setObject:(Value VPtr)object forKeyedSubscript:(Key<NSCopying> KPtr)key; \
- (void)setValue:(Value VPtr)value forKey:(NSString *)key; \
- (void)addEntriesFromDictionary:(TDictionary(Key, Value))other; \
- (void)setDictionary:(TDictionary(Key, Value))other; \
/*! Removing Entries */ \
- (void)removeObjectForKey:(Key KPtr)key; \
- (void)removeObjectsForKeys:(TArray(Key))keys; \
- (void)removeAllObjects; \
@end


