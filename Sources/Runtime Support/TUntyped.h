//
//  TUntyped.h
//  Typed
//
//  Created by Martin Kiss on 17.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import <Foundation/Foundation.h>



@interface NSArray (TUntyped)
- (instancetype)untyped;
@end



@interface NSSet (TUntyped)
- (instancetype)untyped;
@end



@interface NSOrderedSet (TUntyped)
- (instancetype)untyped;
@end



@interface NSDictionary (TUntyped)
- (instancetype)untyped;
@end



@interface NSCache (TUntyped)
- (instancetype)untyped;
@end


