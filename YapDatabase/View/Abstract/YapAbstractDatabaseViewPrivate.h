#import <Foundation/Foundation.h>

#import "YapAbstractDatabaseView.h"
#import "YapAbstractDatabaseViewConnection.h"
#import "YapAbstractDatabaseViewTransaction.h"

#import "YapAbstractDatabaseConnection.h"
#import "YapAbstractDatabaseTransaction.h"


@interface YapAbstractDatabaseView ()

@property (atomic, copy, readwrite) NSString *registeredName;

- (NSString *)tableName;

- (YapAbstractDatabaseViewConnection *)newConnection;

@end

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

@interface YapAbstractDatabaseViewConnection () {
@public
	YapAbstractDatabaseView *abstractView;
}

- (id)initWithDatabaseView:(YapAbstractDatabaseView *)parent;

- (id)newTransaction:(YapAbstractDatabaseTransaction *)databaseTransaction;

@end

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

@interface YapAbstractDatabaseViewTransaction () {
@protected
	__unsafe_unretained YapAbstractDatabaseViewConnection *abstractViewConnection;
	__unsafe_unretained YapAbstractDatabaseTransaction *databaseTransaction;
}

/**
 * A view transaction is created on-demand from within a database transaction.
 *
 * If the view is requested, it is created once per transaction.
 * If the view is not requested, then it is not created.
 *
 * Additional requests for the same view transaction from within a database transaction return the existing instance.
 * 
 * The view transaction is only valid from within the database transaction.
**/

- (id)initWithViewConnection:(YapAbstractDatabaseViewConnection *)viewConnection
         databaseTransaction:(YapAbstractDatabaseTransaction *)transaction;

- (BOOL)open;
- (BOOL)createOrOpen;

- (void)commitTransaction;

@end

@protocol YapAbstractDatabaseViewKeyValueTransaction
@required

- (void)handleInsertKey:(NSString *)key withObject:(id)object metadata:(id)metadata;
- (void)handleUpdateKey:(NSString *)key withObject:(id)object metadata:(id)metadata;
- (void)handleUpdateKey:(NSString *)key withMetadata:(id)metadata;
- (void)handleRemoveKey:(NSString *)key;
- (void)handleRemoveAllKeys;

@end

@protocol YapAbstractDatabaseViewCollectionKeyValueTransaction
@required

- (void)handleInsertKey:(NSString *)key withObject:(id)object metadata:(id)metadata inCollection:(NSString *)collection;
- (void)handleUpdateKey:(NSString *)key withObject:(id)object metadata:(id)metadata inCollection:(NSString *)collection;
- (void)handleUpdateKey:(NSString *)key withMetadata:(id)metadata inCollection:(NSString *)collection;
- (void)handleRemoveKey:(NSString *)key inCollection:(NSString *)collection;
- (void)handleRemoveAllKeysInCollection:(NSString *)collection;
- (void)handleRemoveAllKeys;

@end