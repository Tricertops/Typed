//
//  main.m
//  Test
//
//  Created by Martin Kiss on 30.10.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

@import Foundation;
#import "Typed.h"



int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        //! LET() for const variables with type inference.
        {
            LET(string =, @"String");
            LET(integer =, 5);
        }
        
        //! VAR() for mutable variables with type inference.
        {
            VAR(string =, @"String");
            string = @"Another";
            VAR(integer =, 5);
            integer += 2;
        }
        
        //! IN() for enumeration with type inference.
        {
            NSArray<NSString *> *fruits = @[ @"Apple", @"Pear", @"Orange" ];
            for IN(fruit in, fruits) {
                (void)fruit.length;
            }
        }
        
        //! MAP() for mapping arrays to other arrays.
        {
            NSArray<NSString *> *fruits = @[ @"Apple", @"Pear", @"Orange" ];
            NSArray<NSNumber *> *lengths = MAP(fruits, NSNumber *, @(x.length)); //! x is implicit name of the enumerated object.
        }
        
        //! All together
        {
            NSDictionary<NSString *, NSDictionary<NSString *, NSURL *> *> *table = nil; // Imagine a table.
            
            LET(resource =, table[@"users"]);
        //  NSDictionary<NSString *, NSURL *> *resource = table[@"GET"];
            
            LET(hosts =, MAP(resource.allValues, NSString *, x.host));
        //  NSMutableArray<NSString *> *hosts = [NSMutableArray new];
        //  for (NSURL *URL in table.allValues)
        //      [hosts addObject: URL.host];
            
            LET(hostsByResource =, MAP(table.allKeys, typeof(hosts), {
                LET(resource =, table[x]);
                LET(hosts =, MAP(resource.allValues, NSString *, x.host));
                yield hosts;
            }));
        //  NSMutableArray<NSArray<NSString *> *> *hostsByResource = [NSMutableArray new];
        //  for (NSString *key in table.allKeys) {
        //      NSDictionary<NSString *, NSURL *> *resource = table[key];
        //      NSMutableArray<NSString *> *hosts = [NSMutableArray new];
        //      for (NSURL *URL in table.allValues)
        //          [hosts addObject: URL.host];
        //      [hostsByResource addObject:hosts];
        //  }
        }
        
        //TODO: Creation of collections with type-checking.
        //TODO: Variadic collection.
    }
    return EXIT_SUCCESS;
}


