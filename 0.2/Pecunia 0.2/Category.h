//
//  Category.h
//  MacBanking
//
//  Created by Frank Emminghaus on 04.07.07.
//  Copyright 2007 Frank Emminghaus. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NSCalendarDate* normalizeDate(NSDate* date);

typedef enum {
	cat_expenses,
	cat_incomes,
	cat_all
} CatValueType;

@class ShortDate;

@interface Category : NSManagedObject {

}

@property (nonatomic, retain) NSString * rule;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSNumber * isBankAcc;
@property (nonatomic, retain) NSString * currency;
@property (nonatomic, retain) Category * parent;
@property (nonatomic, retain) NSString * localName;
@property (nonatomic, retain) NSNumber * isBalanceValid;
@property (nonatomic, retain) NSDecimalNumber * catSum;
@property (nonatomic, retain) NSDecimalNumber * balance;
//@property (nonatomic, retain, readonly) NSString * accountNumber;

//-(NSDecimalNumber*)updateBalance;
-(void)updateInvalidBalances;
-(void)invalidateBalance;
-(NSDecimalNumber*)rollup;
-(void)rebuildValues;

-(NSString*)name;
//-(NSString*)localName;
-(NSString*)accountNumber;
-(BOOL)isRoot;
-(BOOL)isBankAccount;
-(BOOL)isBankingRoot;
-(BOOL)isEditable;
-(BOOL)isRemoveable;
-(BOOL)isInsertable;
-(BOOL)isNotAssignedCategory;
-(BOOL)checkMoveToCategory:(Category*)cat;

//-(void)setLocalName: (NSString*)name;
-(NSMutableSet*)children;
-(NSSet*)allChildren;
-(NSSet*)siblings;
-(NSDictionary*)balanceHistory;
-(NSDecimalNumber*)valuesOfType: (CatValueType)type from: (ShortDate*)fromDate to: (ShortDate*)toDate;
-(NSArray*)statementsFrom: (ShortDate*)fromDate to: (ShortDate*)toDate withChildren: (BOOL)c;
-(NSMutableSet*)combinedStatements;

+(Category*)bankRoot;
+(Category*)catRoot;
+(Category*)nassRoot;
+(void)updateCatValues;
+(void)setCatReportFrom: (ShortDate*)fDate to: (ShortDate*)tDate;

@end