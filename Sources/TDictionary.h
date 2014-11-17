//
//  TDictionary.h
//  Typed
//
//  Created by Martin Kiss on 5.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TCollections.h"



#define _TDictionaryCreateProtocol(Key, KPtr, Value, VPtr) \
/*! Types */ \
typedef void (^TAssociativeEnumerator_##Key##_##Value)(Key<NSCopying> KPtr key, Value VPtr object, BOOL *stop); \
typedef NSComparisonResult (^TComparator_##Value)(Value VPtr object1, Value VPtr object2); \
typedef BOOL (^TAssociativePredicate_##Key##_##Value)(Key<NSCopying> KPtr key, Value VPtr object, BOOL *stop); \
_TArrayForward(Key) \
_TArrayForward(Value) \
_TSetForward(Key) \
_TDictionaryForward(NSString, Value); \
_TMutableDictionaryForward(Key, Value); \
/*! NSDictionary Interface */ \
_TDictionaryForward(Key, Value); \
@protocol TDictionary_##Key##_##Value <_TProtocols> \
- (TDictionary(Key, Value))self; \
/*! Initializing a Dictionary */ \
- (TDictionary(Key, Value))initWithDictionary:(TDictionary(Key, Value))other; \
- (TDictionary(Key, Value))initWithDictionary:(TDictionary(Key, Value))other copyItems:(BOOL)flag; \
- (TDictionary(Key, Value))initWithObjects:(TArray(Value))objects forKeys:(TArray(Key))keys; \
- (TDictionary(Key, Value))initWithObjects:(const Value VPtr __autoreleasing [])objects forKeys:(const Key<NSCopying> KPtr __autoreleasing [])keys count:(NSUInteger)count; \
- (TDictionary(Key, Value))initWithObjectsAndKeys:(Value VPtr)firstObject, ... NS_REQUIRES_NIL_TERMINATION; \
- (TDictionary(Key, Value))initWithContentsOfFile:(NSString *)path; \
- (TDictionary(Key, Value))initWithContentsOfURL:(NSURL *)url; \
- (TDictionary(Key, Value))init; \
- (TDictionary(Key, Value))initWithCoder:(NSCoder *)decoder; \
/*! Querying a Dictionary */ \
@property(readonly) NSUInteger count; \
@property(readonly, copy) TArray(Key) allKeys; \
@property(readonly, copy) TArray(Value) allValues; \
- (TArray(Key))allKeysForObject:(Value VPtr)object; \
- (Value VPtr)objectForKey:(Key<NSCopying> KPtr)key; \
- (Value VPtr)objectForKeyedSubscript:(Key<NSCopying> KPtr)key; \
- (TArray(Value))objectsForKeys:(TArray(Key))keys notFoundMarker:(NSObject *)object; \
- (NSEnumerator *)keyEnumerator; \
- (NSEnumerator *)objectEnumerator; \
- (void)getObjects:(Value VPtr __unsafe_unretained [])objects andKeys:(Key<NSCopying> KPtr __unsafe_unretained [])keys; \
- (void)enumerateKeysAndObjectsUsingBlock:(TAssociativeEnumerator_##Key##_##Value)block; \
- (void)enumerateKeysAndObjectsWithOptions:(NSEnumerationOptions)options usingBlock:(TAssociativeEnumerator_##Key##_##Value)block; \
/*! Comparing Dictionaries */ \
- (BOOL)isEqual:(TDictionary(Key, Value))other; \
- (BOOL)isEqualToDictionary:(TDictionary(Key, Value))other; \
/*! Copying a Dictionary */ \
- (TDictionary(Key, Value))copy; \
- (TDictionary(Key, Value))copyWithZone:(NSZone *)zone; \
- (TMutableDictionary(Key, Value))mutableCopy; \
- (TMutableDictionary(Key, Value))mutableCopyWithZone:(NSZone *)zone; \
/*! Sorting a Dictionary */ \
- (TArray(Key))keysSortedByValueUsingSelector:(SEL)comparator; \
- (TArray(Key))keysSortedByValueUsingComparator:(TComparator_##Value)comparator; \
- (TArray(Key))keysSortedByValueWithOptions:(NSSortOptions)options usingComparator:(TComparator_##Value)comparator; \
/*! Filtering a Dictionary */ \
- (TSet(Key))keysOfEntriesPassingTest:(TAssociativePredicate_##Key##_##Value)predicate; \
- (TSet(Key))keysOfEntriesWithOptions:(NSEnumerationOptions)options passingTest:(TAssociativePredicate_##Key##_##Value)predicate; \
/*! Creating a Description */ \
@property(readonly, copy) NSString *description; \
@property(readonly, copy) NSString *descriptionInStringsFileFormat; \
- (NSString *)descriptionWithLocale:(id)locale; \
- (NSString *)descriptionWithLocale:(id)locale indent:(NSUInteger)level; \
- (BOOL)writeToFile:(NSString *)path atomically:(BOOL)flag; \
- (BOOL)writeToURL:(NSURL *)aURL atomically:(BOOL)flag; \
/*! Key-Value Coding */ \
- (Value VPtr)valueForKey:(NSString *)key; \
- (void)setValue:(Value VPtr)value forKey:(NSString *)key; \
- (id)valueForKeyPath:(NSString *)keyPath; \
- (void)setValue:(id)value forKeyPath:(NSString *)keyPath; \
- (TDictionary(NSString, Value))dictionaryWithValuesForKeys:(TArray(NSString))keys; \
- (void)setValuesForKeysWithDictionary:(TDictionary(NSString, Value))keyedValues; \
@end


