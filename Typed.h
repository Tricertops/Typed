//
//  Typed.h
//  Typed
//
//  Created by Martin Kiss on 30.10.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

@import Foundation;



typedef NSObject TArray;



#define TArray(Class)   TArray<TArray_##Class>



#define TArrayGenerate(Class) \
@class Class; \
@protocol TArray_##Class <NSObject> \
- (NSString *)objectAtIndex:(NSUInteger)index; \
@end \
@interface NSArray (TArray_##Class) <TArray_##Class> @end \


