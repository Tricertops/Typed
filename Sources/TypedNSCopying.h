//
//  TypedNSCopying.h
//  Typed
//
//  Created by Martin Kiss on 24 May 2017.
//  https://github.com/Tricertops/Typed
//
//  The MIT License (MIT)
//  Copyright © 2017 Martin Kiss
//



//! Many classes that conform to NSCopying and mainly to NSMutableCopying are extended to provide type inferrence hint about their copies.



@interface NSArray<ElementType> (TypedNSCopying)

- (NSArray<ElementType> *)copy;
- (NSMutableArray<ElementType> *)mutableCopy;

@end



@interface NSSet<ElementType> (TypedNSCopying)

- (NSSet<ElementType> *)copy;
- (NSMutableSet<ElementType> *)mutableCopy;

@end



@interface NSOrderedSet<ElementType> (TypedNSCopying)

- (NSOrderedSet<ElementType> *)copy;
- (NSMutableOrderedSet<ElementType> *)mutableCopy;

@end



@interface NSHashTable<ElementType> (TypedNSCopying)

- (instancetype)copy;

@end



@interface NSDictionary<KeyType, ValueType> (TypedNSCopying)

- (NSDictionary<KeyType, ValueType> *)copy;
- (NSMutableDictionary<KeyType, ValueType> *)mutableCopy;

@end



@interface NSMapTable<KeyType, ValueType> (TypedNSCopying)

- (instancetype)copy;

@end



@interface NSAttributedString (TypedNSCopying)

- (NSAttributedString *)copy;
- (NSMutableAttributedString *)mutableCopy;

@end



@interface NSCharacterSet (TypedNSCopying)

- (NSCharacterSet *)copy;
- (NSMutableCharacterSet *)mutableCopy;

@end



@interface NSData (TypedNSCopying)

- (NSData *)copy;
- (NSMutableData *)mutableCopy;

@end



@interface NSIndexSet (TypedNSCopying)

- (NSIndexSet *)copy;
- (NSMutableIndexSet *)mutableCopy;

@end



#if defined(APPKIT_EXTERN) || defined(UIKIT_EXTERN)

@interface NSParagraphStyle (TypedNSCopying)

- (NSParagraphStyle *)copy;
- (NSMutableParagraphStyle *)mutableCopy;

@end

@interface NSShadow (TypedNSCopying)

- (instancetype)copy;

@end

#endif



@interface NSString (TypedNSCopying)

- (NSString *)copy;
- (NSMutableString *)mutableCopy;

@end



@interface NSURLRequest (TypedNSCopying)

- (NSURLRequest *)copy;
- (NSMutableURLRequest *)mutableCopy;

@end



@interface NSDateComponents (TypedNSCopying)

- (instancetype)copy;

@end



@interface NSURLComponents (TypedNSCopying)

- (instancetype)copy;

@end



#if defined(APPKIT_EXTERN)

@interface NSBezierPath (TypedNSCopying)

- (instancetype)copy;

@end

#endif



#if defined(UIKIT_EXTERN)

@interface UIBezierPath (TypedNSCopying)

- (instancetype)copy;

@end

#endif


