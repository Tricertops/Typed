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
typedef void (^TAssociativeEnumerator_##Key##_##Value)(Key<NSCopying> *key, Value *object, BOOL *stop); \
typedef NSComparisonResult (^TComparator_##Value)(Value *object1, Value *object2); \
typedef BOOL (^TAssociativePredicate_##Key##_##Value)(Key<NSCopying> *key, Value *object, BOOL *stop); \
_TArrayForward(Key) \
_TArrayForward(Value) \
_TSetForward(Key) \
_TDictionaryForward(NSString, Value); \
/*! NSDictionary Interface */ \
@protocol TDictionary_##Key##_##Value <_TAssociativeProtocols> \
- (TDictionary(Key, Value))self; \
/*! Initializing a Dictionary */ \
- (TDictionary(Key, Value))initWithDictionary:(TDictionary(Key, Value))other; \
- (TDictionary(Key, Value))initWithDictionary:(TDictionary(Key, Value))other copyItems:(BOOL)flag; \
- (TDictionary(Key, Value))initWithObjects:(TArray(Value))objects forKeys:(TArray(Key))keys; \
- (TDictionary(Key, Value))initWithObjects:(const Value * __autoreleasing [])objects forKeys:(const Key<NSCopying> * __autoreleasing [])keys count:(NSUInteger)count; \
- (TDictionary(Key, Value))initWithObjectsAndKeys:(Value *)firstObject, ... NS_REQUIRES_NIL_TERMINATION; \
- (TDictionary(Key, Value))initWithContentsOfFile:(NSString *)path; \
- (TDictionary(Key, Value))initWithContentsOfURL:(NSURL *)url; \
- (TDictionary(Key, Value))init; \
- (TDictionary(Key, Value))initWithCoder:(NSCoder *)decoder; \
/*! Querying a Dictionary */ \
@property(readonly) NSUInteger count; \
@property(readonly, copy) TArray(Key) allKeys; \
@property(readonly, copy) TArray(Value) allValues; \
- (TArray(Key))allKeysForObject:(Value *)object; \
- (Value *)objectForKey:(Key<NSCopying> *)key; \
- (Value *)objectForKeyedSubscript:(Key<NSCopying> *)key; \
- (TArray(Value))objectsForKeys:(TArray(Key))keys notFoundMarker:(NSObject *)object; \
- (NSEnumerator *)keyEnumerator; \
- (NSEnumerator *)objectEnumerator; \
- (void)getObjects:(Value * __unsafe_unretained [])objects andKeys:(Key<NSCopying> * __unsafe_unretained [])keys; \
- (void)enumerateKeysAndObjectsUsingBlock:(TAssociativeEnumerator_##Key##_##Value)block; \
- (void)enumerateKeysAndObjectsWithOptions:(NSEnumerationOptions)options usingBlock:(TAssociativeEnumerator_##Key##_##Value)block; \
/*! Comparing Dictionaries */ \
- (BOOL)isEqual:(TDictionary(Key, Value))other; \
- (BOOL)isEqualToDictionary:(TDictionary(Key, Value))other; \
/*! Copying a Dictionary */ \
- (TDictionary(Key, Value))copy; \
- (TDictionary(Key, Value))copyWithZone:(NSZone *)zone; \
- (TDictionary(Key, Value))mutableCopy; \
- (TDictionary(Key, Value))mutableCopyWithZone:(NSZone *)zone; \
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
- (Value *)valueForKey:(NSString *)key; \
- (void)setValue:(Value *)value forKey:(NSString *)key; \
- (id)valueForKeyPath:(NSString *)keyPath; \
- (void)setValue:(id)value forKeyPath:(NSString *)keyPath; \
- (TDictionary(NSString, Value))dictionaryWithValuesForKeys:(TArray(NSString))keys; \
- (void)setValuesForKeysWithDictionary:(TDictionary(NSString, Value))keyedValues; \
@end


