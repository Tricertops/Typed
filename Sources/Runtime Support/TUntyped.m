//
//  TUntyped.m
//  Typed
//
//  Created by Martin Kiss on 17.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import <Foundation/Foundation.h>



// This crap is here to supress compiler warning about empty library. It’s not empty, you see?
@interface TypedLibraryPresence : NSObject @end
@implementation TypedLibraryPresence @end




//! These categories provide implementation for -untyped method which simply returns self.




@implementation NSArray (TUntyped)
- (instancetype)untyped {
    return self;
}
@end



@implementation NSSet (TUntyped)
- (instancetype)untyped {
    return self;
}
@end



@implementation NSOrderedSet (TUntyped)
- (instancetype)untyped {
    return self;
}
@end



@implementation NSDictionary (TUntyped)
- (instancetype)untyped {
    return self;
}
@end



@implementation NSCache (TUntyped)
- (instancetype)untyped {
    return self;
}
@end



@implementation NSPointerArray (TUntyped)
- (instancetype)untyped {
    return self;
}
@end



@implementation NSHashTable (TUntyped)
- (instancetype)untyped {
    return self;
}
@end


