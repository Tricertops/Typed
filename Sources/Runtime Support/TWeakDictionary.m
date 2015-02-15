//
//  TWeakDictionary.m
//  Typed
//
//  Created by Martin Kiss on 15.2.15.
//  Copyright (c) 2015 Triceratops. All rights reserved.
//

#import <Foundation/NSMapTable.h>



//! This category provides implementations for new and renamed method of NSMapTable, a.k.a. TWeakDictionary.



@implementation NSMapTable (TWeakDictionary)





+ (instancetype)weakToWeak {
    return [self weakToWeakObjectsMapTable];
}


+ (instancetype)weakToStrong {
    return [self weakToStrongObjectsMapTable];
}


+ (instancetype)strongToWeak {
    return [self strongToWeakObjectsMapTable];
}





- (NSDictionary *)strong {
    return self.dictionaryRepresentation;
}





- (id)objectForKeyedSubscript:(id)key {
    return [self objectForKey:key];
}


- (void)setObject:(id)object forKeyedSubscript:(NSString *)key {
    [self setObject:object forKey:key];
}





@end


