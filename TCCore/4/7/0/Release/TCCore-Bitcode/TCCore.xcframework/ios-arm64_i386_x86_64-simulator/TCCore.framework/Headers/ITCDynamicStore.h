//
//  ITCDynamicStore.h
//  TagCommander

#import <Foundation/Foundation.h>

@class TCDynamicStore;

/**
* @protocol ITCDynamicStore
*
* The ITCDynamicStore protocol is a protocol to store dynamic variables.
*
* At its core, a dynamic store is a dictionary containing one value for each variable name
*/
@protocol ITCDynamicStore <NSObject>

/**
 * Add a complete store to the current one.
 * @param store the store to add.
 */
- (void) addData: (TCDynamicStore *) store;

/**
 * Simplified implementation of adding a variable in a TCDynamicStore
 * @param key The key for the store.
 * @param value the value of the dynamic variable.
 */
- (void) addData: (NSString *) key withValue: (NSString *) value;

/**
 * Get the raw string value without applying the functions.
 * @param key The key.
 * @return the raw value.
 */
- (NSString *) getData: (NSString *) key;

/**
 * Remove one value in a TCDynamicStore.
 * Does nothing if the variable is not is the store.
 * @param key the variable to be removed.
 * @return the value of the removed key.
 */
- (NSString *) removeData: (NSString *) key;

/**
 * Store cleaning.
 */
- (void) clearData;

@end
