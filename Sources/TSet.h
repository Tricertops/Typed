//
//  TSet.h
//  Typed
//
//  Created by Martin Kiss on 2.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TCollections.h"



_TArrayForward(NSString)
_TArrayForward(NSSortDescriptor)
_TDictionaryForward(NSString, NSObject)



#define _TSetCreateProtocol(Element, Ptr) \
/*! Types */ \
typedef void (^TEnumerator_##Element)(Element Ptr object, BOOL *stop); \
typedef BOOL (^TPredicate_##Element)(Element Ptr object, BOOL *stop); \
_TArrayForward(Element) \
_TMutableSetForward(Element) \
/*! NSSet Interface */ \
_TSetForward(Element) \
@protocol TSet_##Element <_TProtocols> \
- (TSet(Element))self; \
- (NSSet *)untyped; \
- (Element Ptr)T_Element; \
- (Element Ptr)T_Enumeration; \
/*! Initializing a Set */ \
- (TSet(Element))initWithArray:(TArray(Element))array; \
- (TSet(Element))initWithObjects:(Element Ptr )firstObject, ... NS_REQUIRES_NIL_TERMINATION; \
- (TSet(Element))initWithObjects:(const Element Ptr  __autoreleasing [])objects count:(NSUInteger)count; \
- (TSet(Element))initWithSet:(TSet(Element))set; \
- (TSet(Element))initWithSet:(TSet(Element))set copyItems:(BOOL)flag; \
- (TSet(Element))init; \
- (TSet(Element))initWithCoder:(NSCoder *)decoder; \
/*! Querying a Set */ \
@property (readonly) NSUInteger count; \
@property (readonly, copy) TArray(Element) allObjects; \
- (Element Ptr )anyObject; \
- (BOOL)containsObject:(Element Ptr )object; \
- (Element Ptr )member:(Element Ptr )object; \
- (NSEnumerator *)objectEnumerator; \
/*! Sending Messages to Elements */ \
- (void)makeObjectsPerformSelector:(SEL)aSelector; \
- (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(id)argument; \
- (void)enumerateObjectsUsingBlock:(TEnumerator_##Element)block; \
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)options usingBlock:(TEnumerator_##Element)block; \
/*! Comparing Sets */ \
- (BOOL)isEqual:(TSet(Element))other; \
- (BOOL)isEqualToSet:(TSet(Element))other; \
- (BOOL)isSubsetOfSet:(TSet(Element))other; \
- (BOOL)intersectsSet:(TSet(Element))other; \
/*! Copying a Set */ \
- (TSet(Element))copy; \
- (TSet(Element))copyWithZone:(NSZone *)zone; \
- (TMutableSet(Element))mutableCopy; \
- (TMutableSet(Element))mutableCopyWithZone:(NSZone *)zone; \
/*! Deriving New Sets */ \
- (TSet(Element))setByAddingObject:(Element Ptr )object; \
- (TSet(Element))setByAddingObjectsFromSet:(TSet(Element))other; \
- (TSet(Element))setByAddingObjectsFromArray:(TArray(Element))array; \
- (TSet(Element))filteredSetUsingPredicate:(NSPredicate *)predicate; \
- (TSet(Element))objectsPassingTest:(TPredicate_##Element)predicate; \
- (TSet(Element))objectsWithOptions:(NSEnumerationOptions)options passingTest:(TPredicate_##Element)predicate; \
/*! Creating a Sorted Array */ \
- (TArray(Element))sortedArrayUsingDescriptors:(TArray(NSSortDescriptor))sortDescriptors; \
/*! Creating a Description */ \
@property (readonly, copy) NSString *description; \
- (NSString *)descriptionWithLocale:(id)locale; \
/*! Key-Value Coding */ \
- (id)valueForKey:(NSString *)key; \
- (void)setValue:(id)value forKey:(NSString *)key; \
- (id)valueForKeyPath:(NSString *)keyPath; \
- (void)setValue:(id)value forKeyPath:(NSString *)keyPath; \
- (TDictionary(NSString, NSObject))dictionaryWithValuesForKeys:(TArray(NSString))keys; \
- (void)setValuesForKeysWithDictionary:(TDictionary(NSString, NSObject))keyedValues; \
@end


