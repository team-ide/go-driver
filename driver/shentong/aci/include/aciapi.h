#pragma once

#include "acitype.h"
#include <stdlib.h>
#include <stdarg.h>

/*-----------------------Dynamic Callback Function Pointers------------------*/


typedef sb4 (*ACICallbackInBind)(dvoid *ictxp, ACIBind *bindp, ub4 iter,
    ub4 index, dvoid **bufpp, ub4 *alenp, ub1 *piecep, dvoid **indp);

typedef sb4 (*ACICallbackOutBind)(dvoid *octxp, ACIBind *bindp, ub4 iter,
    ub4 index, dvoid **bufpp, ub4 **alenp, ub1 *piecep, dvoid **indp,
    ub2 **rcodep);

typedef sb4 (*ACICallbackDefine)(dvoid *octxp, ACIDefine *defnp, ub4 iter,
    dvoid **bufpp, ub4 **alenp, ub1 *piecep, dvoid **indp, ub2 **rcodep);

typedef sword (*ACIUserCallback)(dvoid *ctxp, dvoid *hndlp, ub4 type,
    ub4 fcode, ub4 when, sword returnCode, sb4 *errnop, va_list arglist);

typedef sword (*ACIEnvCallbackType)(ACIEnv *env, ub4 mode, size_t xtramem_sz,
    dvoid *usrmemp, ACIUcb *ucbDesc);

typedef sb4 (*ACICallbackLobRead)(dvoid *ctxp, CONST dvoid *bufp, ub4 len,
    ub1 piece);

typedef sb4 (*ACICallbackLobRead2)(dvoid *ctxp, CONST dvoid *bufp, aciub8 lenp,
								   ub1 piecep, dvoid **changed_bufpp, aciub8 *changed_lenp);

typedef sb4 (*ACICallbackLobWrite)(dvoid *ctxp, dvoid *bufp, ub4 *lenp,
    ub1 *piece);

typedef sb4 (*ACICallbackLobWrite2)(dvoid *ctxp, dvoid *bufp, aciub8 *lenp,
									ub1 *piecep, dvoid **changed_bufpp, aciub8 *changed_lenp);

typedef sb4 (*ACICallbackAQEnq)(dvoid *ctxp, dvoid **payload,
    dvoid **payload_ind);

typedef sb4 (*ACICallbackAQDeq)(dvoid *ctxp, dvoid **payload,
    dvoid **payload_ind);

/*--------------------------Failover Callback Structure ---------------------*/
typedef sb4 (*ACICallbackFailover)(dvoid *svcctx, dvoid *envctx,
                                   dvoid *fo_ctx, ub4 fo_type,
                                   ub4 fo_event);
typedef struct
{
    ACICallbackFailover callback_function;
    dvoid *fo_ctx;
} 
ACIFocbkStruct;

/*---------------------Statement Cache callback function ------------------*/
typedef sword(*ACICallbackStmtCache)(void* ctx, ACIStmt* stmt, ub4 mode);

/*--------------------------HA Callback Structure ---------------------*/
typedef void (*ACIEventCallback)(dvoid *evtctx, ACIEvent *eventhp);


sword ACIInitialize(ub4 mode, dvoid *ctxp, dvoid *(*malocfp)(dvoid *ctxp,
    size_t size), dvoid *(*ralocfp)(dvoid *ctxp, dvoid *memptr,
    size_t newsize), void(*mfreefp)(dvoid *ctxp, dvoid *memptr));

sword ACIEnvInit(ACIEnv **envp, ub4 mode, size_t xtramem_sz, dvoid **usrmempp);

sword ACIHandleAlloc(CONST dvoid *parenth, dvoid **hndlpp, CONST ub4 type,
    CONST size_t xtramem_sz, dvoid **usrmempp);

sword ACIHandleFree(dvoid *hndlp, CONST ub4 type);

sword ACIServerAttach(ACIServer *srvhp, ACIError *errhp, CONST OraText *dblink,
    sb4 dblink_len, ub4 mode);

sword ACIServerDetach(ACIServer *srvhp, ACIError *errhp, ub4 mode);

sword ACISessionBegin(ACISvcCtx *svchp, ACIError *errhp, ACISession *usrhp,
    ub4 credt, ub4 mode);

sword ACISessionEnd(ACISvcCtx *svchp, ACIError *errhp, ACISession *usrhp,
    ub4 mode);

sword ACILogon(ACIEnv *envhp, ACIError *errhp, ACISvcCtx **svchp,
    CONST OraText *username, ub4 uname_len, CONST OraText *password,
    ub4 passwd_len, CONST OraText *dbname, ub4 dbname_len);

sword ACILogon2 (ACIEnv *envhp, ACIError *errhp, ACISvcCtx **svchp,
      const OraText *username, ub4 uname_len,
      const OraText *password, ub4 passwd_len,
      const OraText *dbname, ub4 dbname_len,
      ub4 mode);

sword ACILogoff(ACISvcCtx *svchp, ACIError *errhp);

sword ACIConnectionPoolCreate(ACIEnv *envhp, ACIError *errhp, ACICPool *poolhp,                    
      OraText **poolName, sb4 *poolNameLen, const OraText  *dblink, sb4 dblinkLen, 
      ub4 connMin, ub4 connMax, ub4 connIncr, 
      const OraText *poolUsername, sb4 poolUserLen,
      const OraText *poolPassword, sb4 poolPassLen, ub4 mode);

sword ACISessionPoolCreate(ACIEnv *envhp, ACIError *errhp, ACISPool *spoolhp,
	OraText **poolName, ub4 *poolNameLen, const OraText  *connStr, ub4 connStrLen,
	ub4 sessMin, ub4 sessMax, ub4 sessIncr,
	const OraText *userid, ub4 useridLen,
	const OraText *password, ub4 passwordLen,
	ub4 mode);

sword ACIConnectionPoolDestroy(ACICPool *poolhp, ACIError *errhp, ub4 mode);
sword ACISessionPoolDestroy(ACISPool *poolhp, ACIError *errhp, ub4 mode);

sword ACISessionGet(ACIEnv *envhp, ACIError *errhp, ACISvcCtx **svchp, ACIAuthInfo *authInfop,
                    OraText *dbName, ub4 dbName_len,
                    const OraText *tagInfo, ub4 tagInfo_len,
                    OraText **retTagInfo, ub4 *retTagInfo_len,
                    sb4 *found, ub4 mode );

sword ACISessionRelease (ACISvcCtx *svchp, ACIError *errhp, OraText *tag, ub4 tag_len, ub4 mode);

sword ACIStmtPrepare(ACIStmt *stmtp, ACIError *errhp, CONST OraText *stmt,
    ub4 stmt_len, ub4 language, ub4 mode);

sword ACIStmtPrepare2( ACISvcCtx *svchp, ACIStmt **stmtp, ACIError *errhp,
    const OraText *stmt, ub4 stmt_len, const OraText *key,
    ub4 key_len, ub4 language, ub4 mode);

sword ACIPrepareForQuUpdate(ACISvcCtx *svchp, ACIStmt *stmtp, ACIError *errhp,
	const OraText *stmt, ub4 stmtlen, ub4 language, ub4 mode);

sword ACIPrepareForUpdate(ACISvcCtx *svchp, ACIStmt *stmtp, ACIError *errhp, 
	acitext *db,  ub2 db_len, acitext *schema, ub2 schema_len, acitext *table, 
	ub2 table_len, acitext *column, ub2 column_len, ub4 *itersp);

sword ACIStmtExecute(ACISvcCtx *svchp, ACIStmt *stmtp, ACIError *errhp,
    ub4 iters, ub4 rowoff, CONST ACISnapshot *snap_in,
    ACISnapshot *snap_out, ub4 mode);

sword ACIExecuteForQuUpdate(ACISvcCtx *svchp, ACIStmt *stmtp, ACIError *errhp,
							ub4 iters, ub4 rowoff, ub4 mode);

sword  ACIExecuteForUpdate(ACISvcCtx *svchp, ACIStmt *stmtp, ACIError *errhp, ub4 rowoff, ub4 mode);

sword ACIStmtRelease(ACIStmt *stmthp, ACIError *errhp, CONST acitext *key,
                                ub4 keylen, ub4 mode);

sword ACIStmtFetch(ACIStmt *stmtp, ACIError *errhp, ub4 nrows, ub2 orientation,
    ub4 mode);

sword ACIStmtFetch2(ACIStmt *stmtp, ACIError *errhp, ub4 nrows, 
    ub2 orientation, sb4 scrollOffset, ub4 mode);

sword ACITransCommit(ACISvcCtx *svchp, ACIError *errhp, ub4 flags);

sword ACITransRollback(ACISvcCtx *svchp, ACIError *errhp, ub4 flags);

sword ACIBindByName(ACIStmt *stmtp, ACIBind **bindp, ACIError *errhp,
    CONST OraText *placeholder, sb4 placeh_len, dvoid *valuep,
    sb4 value_sz, ub2 dty, dvoid *indp, ub2 *alenp, ub2 *rcodep,
    ub4 maxarr_len, ub4 *curelep, ub4 mode);

sword ACIBindByName2(ACIStmt *stmtp, ACIBind **bindp, ACIError *errhp,
	CONST OraText *placeholder, sb4 placeh_len, dvoid *valuep,
	sb8 value_sz, ub2 dty, dvoid *indp, ub4 *alenp, ub2 *rcodep,
	ub4 maxarr_len, ub4 *curelep, ub4 mode);

sword ACIBindByPos(ACIStmt *stmtp, ACIBind **bindp, ACIError *errhp,
    ub4 position, dvoid *valuep, sb4 value_sz, ub2 dty, dvoid *indp,
    ub2 *alenp, ub2 *rcodep, ub4 maxarr_len, ub4 *curelep, ub4 mode);

sword ACIBindByPos2(ACIStmt *stmtp, ACIBind **bindp, ACIError *errhp,
					ub4 position, dvoid *valuep, sb8 value_sz,
					ub2 dty, dvoid *indp, ub4 *alenp, ub2 *rcodep,
					ub4 maxarr_len, ub4 *curelep, ub4 mode);

sword ACIBindDynamic(ACIBind *bindp, ACIError *errhp, void *ictxp, 
					 ACICallbackInBind icbfp,
					 void *octxp,
					 ACICallbackOutBind ocbfp);

sword ACIBindObject(ACIBind* bindp, ACIError* errhp, const ACIType* type,
    void** pgvpp, ub4* pvszsp, void** indpp,
    ub4* indszp);

sword ACIBindArrayOfStruct(ACIBind *bindp, ACIError *errhp, ub4 pvskip,
    ub4 indskip, ub4 alskip, ub4 rcskip);

sword ACIBindParamForQuUpdate(ACISvcCtx *svchp, ACIStmt *stmtp, ACIError *errhp, 
							  ub4 position, void *valuep, ub4 valuesz, ub4 valueskip,
							  ub2 dty, sb2 *indp, ub4 indskip, ub4 mode);

sword  ACIBindParamForUpdate(ACISvcCtx *svchp, ACIStmt *stmtp, ACIError *errhp, 
							 dvoid *value_pkp, ub4 ppkvskip, dvoid *valuep, sb4 value_sz, 
							 ub4 pvskip, ub2 dty, dvoid *indp, ub4 indskip);

sword ACIDefineByPos(ACIStmt *stmtp, ACIDefine **defnp, ACIError *errhp,
    ub4 position, dvoid *valuep, sb4 value_sz, ub2 dty, dvoid *indp,
    ub2 *rlenp, ub2 *rcodep, ub4 mode);

sword ACIDefineByPos2(ACIStmt *stmtp, ACIDefine **defnp, ACIError *errhp,
    ub4 position, dvoid *valuep, sb8 value_sz, ub2 dty, dvoid *indp,
    ub4 *rlenp, ub2 *rcodep, ub4 mode);

sword ACIDefineArrayOfStruct(ACIDefine *defnp, ACIError *errhp, ub4 pvskip,
    ub4 indskip, ub4 rlskip, ub4 rcskip);

sword ACIDefineDynamic(ACIDefine *defnp, ACIError *errhp, void *octxp, ACICallbackDefine ocbfp);

sword  ACIDefineObject(ACIDefine* defnp, ACIError* errhp,
    const ACIType* type, void** pgvpp,
    ub4* pvszsp, void** indpp, ub4* indszp);

sword ACIDescriptorAlloc(CONST dvoid *parenth, dvoid **descpp, CONST ub4 type,
    CONST size_t xtramem_sz, dvoid **usrmempp);

sword ACIArrayDescriptorAlloc(CONST dvoid *parenth, dvoid **descpp,
	CONST ub4 type, sb4 array_size, CONST size_t xtramem_sz, dvoid **usrmempp);

sword ACIDescriptorFree(dvoid *descp, CONST ub4 type);

sword ACIArrayDescriptorFree(dvoid **descp, CONST ub4 type);

sword ACILobGetLength(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *locp,
    ub4 *lenp);

sword ACILobRead(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *locp,
    ub4 *amtp, ub4 offset, dvoid *bufp, ub4 bufl, dvoid *ctxp,
    ACICallbackLobRead cbfp, ub2 csid, ub1 csfrm);

sword ACILobWrite(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *locp,
    ub4 *amtp, ub4 offset, dvoid *bufp, ub4 buflen, ub1 piece, dvoid *ctxp,
    ACICallbackLobWrite cbfp, ub2 csid, ub1 csfrm);

sword ACILobFileGetName(ACIEnv *envhp, ACIError *errhp, const ACILobLocator *filep, 
    OraText *dir_alias, ub2 *d_length, OraText *filename, ub2 *f_length);

sword ACILobFileExists(ACISvcCtx *svchp, ACIError *errhp, 
    ACILobLocator *filep, sb4 *flag);

sword ACILobFileOpen(ACISvcCtx *svchp, ACIError *errhp, 
    ACILobLocator *filep, ub1 mode);

sword ACILobFileClose(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *filep);

sword ACILobErase(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *locp,
    ub4 *amount, ub4 offset);

sword ACILobErase2(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *locp,
				   aciub8 *amount, aciub8 offset);

sword ACILobTrim(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *locp,
    ub4 newlen);

sword ACILobCreateTemporary(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator*locp,
    ub2 csid, ub1 csfrm, ub1 lobtype, int cache, ACIDuration duration);

sword ACILobFreeTemporary(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *locp);

sword ACILobIsTemporary(ACIEnv *envhp, ACIError *errhp, ACILobLocator *locp, 
						sb4 *temporary);

sword ACILobFileIsOpen(ACISvcCtx *svchp, ACIError *errhp, 
    ACILobLocator *filep, sb4 *flag);

sword ACILobFileSetName(ACIEnv *envhp, ACIError *errhp, ACILobLocator **filepp, 
    const OraText *dir_alias, ub2 d_length, const OraText *filename, ub2 f_length);

sword ACILobLocatorIsInit(ACIEnv *envhp, ACIError *errhp,
    const ACILobLocator *locp, sb4 *is_initialized);

sword ACILobGetLength2 (ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *locp, aciub8 *lenp);

sword ACILobAppend(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *dst_locp,
				   ACILobLocator *src_locp);

sword ACILobTrim2(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *locp,
				  aciub8 newlen);

sword ACILobWrite2(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *locp,
				   aciub8 *byte_amtp, aciub8 *char_amtp, aciub8 offset, 
				   dvoid *bufp, aciub8 buflen, ub1 piece, dvoid *ctxp, 
				   ACICallbackLobWrite2 cbfp, ub2 csid, ub1 csfrm);

sword ACILobRead2(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *locp,
				  aciub8 *byte_amtp, aciub8 *char_amtp, aciub8 offset, 
				  dvoid *bufp, aciub8 bufl, ub1 piece, dvoid *ctxp, 
				  ACICallbackLobRead2 cbfp, ub2 csid, ub1 csfrm);

sword ACILobWriteAppend(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *locp,
						ub4 *amtp, dvoid *bufp, ub4 buflen, ub1 piece,
						dvoid *ctxp, ACICallbackLobWrite cbfp, ub2 csid,
						ub1 csfrm);

sword ACILobWriteAppend2(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *locp,
						 aciub8 *byte_amtp, aciub8 *char_amtp, dvoid *bufp, aciub8 buflen, 
						 ub1 piece, dvoid *ctxp, ACICallbackLobWrite2 cbfp, ub2 csid,
						 ub1 csfrm);

sword ACILobCharSetId(ACIEnv *envhp, ACIError *errhp, const ACILobLocator *locp,
					  ub2 *csid);

sword ACILobCharSetForm(ACIEnv *envhp, ACIError *errhp, const ACILobLocator *locp,
						ub1 *csfrm);

sword ACILobOpen(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *locp, 
				 ub1 mode);

sword ACILobClose(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *locp);

sword ACILobIsOpen(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *locp, sb4 *flag);

sword ACILobAssign(ACIEnv *envhp, ACIError *errhp, const ACILobLocator *src_locp, 
				   ACILobLocator **dst_locpp);

sword ACILobLocatorAssign(ACISvcCtx *svchp, ACIError *errhp, 
						  const ACILobLocator *src_locp, ACILobLocator **dst_locpp);

sword ACILobIsEqual(ACIEnv *envhp, const ACILobLocator *x,											const ACILobLocator *y, sb4 *is_equal);

sword ACILobCopy(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *dst_locp,
				 ACILobLocator *src_locp, ub4 amount, ub4 dst_offset, ub4 src_offset);

sword ACILobCopy2(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *dst_locp, ACILobLocator *src_locp, aciub8 amount, aciub8 dst_offset, aciub8 src_offset);

sword ACILobLoadFromFile(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *dst_locp, ACILobLocator *src_locp, ub4 amount, ub4 dst_offset, ub4 src_offset);

sword ACILobLoadFromFile2(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *dst_locp, ACILobLocator *src_locp, aciub8 amount, aciub8 dst_offset, aciub8 src_offset);

sword ACILobFileCloseAll(ACISvcCtx *svchp, ACIError *errhp);

sword ACILobEnableBuffering(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *locp);

sword ACILobDisableBuffering(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *locp);

sword ACILobFlushBuffer(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *locp, ub4 flag);

sword ACIDurationBegin(ACIEnv *env, ACIError *err, const ACISvcCtx *svc,  ACIDuration parent, ACIDuration *duration);

sword ACIDurationEnd(ACIEnv *env, ACIError *err, const ACISvcCtx *svc,  ACIDuration duration);

sword ACILobGetChunkSize(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *locp, ub4 *chunk_size);

sword ACILobGetStorageLimit(ACISvcCtx *svchp, ACIError *errhp, ACILobLocator *locp, ub8 *limitp);

sword ACIServerDataLengthGet(void *hndlp, ub4 *lengthValidp, ub8 *lengthp, ACIError *errhp, ub4 mode);

sword ACIDescribeAny(ACISvcCtx *svchp, ACIError *errhp, dvoid *objptr,
    ub4 objnm_len, ub1 objptr_typ, ub1 info_level, ub1 objtyp,
    ACIDescribe *dschp);

sword ACIParamGet(CONST dvoid *hndlp, ub4 htype, ACIError *errhp,
    dvoid **parmdpp, ub4 pos);

sword ACIAttrSet(dvoid *trgthndlp, ub4 trghndltyp, dvoid *attributep, ub4 size,
    ub4 attrtype, ACIError *errhp);

sword ACIAttrGet(CONST dvoid *trgthndlp, ub4 trghndltyp, dvoid *attributep,
    ub4 *sizep, ub4 attrtype, ACIError *errhp);

sword ACIErrorGet(dvoid *hndlp, ub4 recordno, acitext *sqlstate, sb4 *errcodep,
    acitext *bufp, ub4 bufsiz, ub4 type);

sword ACIDateTimeConstruct(dvoid *hndl, ACIError *err, ACIDateTime *datetime,
    sb2 year, ub1 month, ub1 day, ub1 hour, ub1 min, ub1 sec, ub4 fsec,
    acitext *timezone, size_t timezone_length);

sword ACIDateTimeGetTime(dvoid *hndl, ACIError *err, ACIDateTime *datetime,
    ub1 *hour, ub1 *min, ub1 *sec, ub4 *fsec);

sword ACIDateTimeGetDate(dvoid *hndl, ACIError *err,
    CONST ACIDateTime *datetime, sb2 *year, ub1 *month, ub1 *day);

sword ACIDateTimeIntervalAdd(void  *hndl, ACIError *err, ACIDateTime *datetime, 
							 ACIInterval *inter, ACIDateTime *outdatetime);

sword ACIDateTimeIntervalSub(void  *hndl, ACIError *err, ACIDateTime *datetime, 
							 ACIInterval *inter, ACIDateTime *outdatetime);

sword ACIDateZoneToZone(ACIError *err, const OCIDate *date1, 
						const OraText *zon1, ub4 zon1_length, 
						const OraText *zon2, ub4 zon2_length, OCIDate *date2);

sword ACIDateAddDays(ACIError *err, const OCIDate *date, sb4 num_days, 
    OCIDate *result);

sword ACIDateAddMonths(ACIError *err, const OCIDate *date, sb4 num_months,
    OCIDate *result);

sword ACIDateAssign(ACIError *err, const OCIDate *from, OCIDate *to);

sword ACIDateCheck(ACIError *err, const OCIDate *date, uword *valid);

sword ACIDateCompare(ACIError *err, const OCIDate *date1, 
    const OCIDate *date2, sword *result);

sword ACIDateDaysBetween(ACIError *err, const OCIDate *date1, 
    const OCIDate *date2, sb4 *num_days);

sword ACIDateFromText(ACIError *err, const OraText *date_str, 
    ub4 d_str_length, const OraText *fmt, ub1 fmt_length, 
    const OraText *lang_name, ub4 lang_length, OCIDate *date );

void ACIDateGetDate(const OCIDate *date, sb2 *year, ub1 *month, ub1 *day );

void ACIDateGetTime(const OCIDate *date, ub1 *hour, ub1 *min, ub1 *sec);

sword ACIDateLastDay( ACIError *err, const OCIDate *date, OCIDate *last_day);

sword ACIDateNextDay(ACIError *err, const OCIDate *date, const OraText *day_p, 
    ub4 day_length, OCIDate *next_day );

void ACIDateSetDate (OCIDate *date, sb2 year, ub1 month, ub1 day );

void ACIDateSetTime ( OCIDate *date, ub1 hour, ub1 min, ub1 sec );

sword ACIDateSysDate(ACIError *err, OCIDate *sys_date);

sword ACIDateToText(ACIError *err, const OCIDate *date, 
                    const OraText *fmt, ub1 fmt_length, 
                    const OraText *lang_name, ub4 lang_length, 
                    ub4 *buf_size, OraText *buf);

sword ACIDateTimeCheck(void  *hndl, ACIError *err, const ACIDateTime *date, 
    ub4 *valid );

sword ACIDateTimeAssign(void *hndl, ACIError *err, const ACIDateTime *from, 
    ACIDateTime *to);

sword ACIDateTimeConvert(void  *hndl, ACIError *err, ACIDateTime *indate,
    ACIDateTime *outdate);

sword ACIDateTimeCompare(void  *hndl, ACIError *err, const ACIDateTime *date1, 
    const ACIDateTime *date2, sword *result);

sword ACIDateTimeFromText(void  *hndl, ACIError *err, const OraText *date_str, 
    size_t dstr_length, const OraText *fmt, 
    ub1 fmt_length, const OraText *lang_name, 
    size_t lang_length, ACIDateTime *date);

sword ACIDateTimeSysTimeStamp(void  *hndl, ACIError *err, 
    ACIDateTime *sys_date );

sword ACIDateTimeSubtract(void  *hndl, ACIError *err, ACIDateTime *indate1, 
    ACIDateTime *indate2, ACIInterval *inter);


sword ACIDateTimeToText(void  *hndl, ACIError *err, const ACIDateTime *date, 
    const OraText *fmt, ub1 fmt_length, ub1 fsprec, 
    const OraText *lang_name, size_t lang_length, 
    ub4 *buf_size, OraText *buf);

sword ACIDateTimeGetTimeZoneName(void  *hndl, ACIError *err, const ACIDateTime *datetime, 
								 ub1 *buf, ub4 *buflen);

sword ACIDateTimeGetTimeZoneOffset(void  *hndl, ACIError *err, const ACIDateTime *datetime, 
								   sb1 *hour, sb1 *min);

sword ACIDateTimeToArray(dvoid *hndl, ACIError *err, const ACIDateTime *datetime, const ACIInterval *reftz, ub1 *outarray, ub4 *len, ub1 fsprec);

sword ACIDateTimeFromArray(dvoid *hndl, ACIError *err, const ub1 *inarray, ub4 len, ub1 type, ACIDateTime *datetime, const ACIInterval *reftz, ub1 fsprec);

sword ACIDateDaysSecondsBetween(ACIError *err, const ACIDateTime *date1, const ACIDateTime *date2, sb4 *num_days, sb4 *num_seconds);

sword ACIIntervalGetDaySecond(void *hndl, ACIError *err, sb4 *dy, sb4 *hr,
    sb4 *mm, sb4 *ss, sb4 *fsec, const ACIInterval *interval);

sword ACIIntervalSetYearMonth(void *hndl, ACIError *err, sb4 yr, sb4 mnth, ACIInterval *result);

sword ACIIntervalGetYearMonth(void *hndl, ACIError *err, sb4 *yr, sb4 *mnth, const ACIInterval *interval);

sword ACIIntervalSetDaySecond(void *hndl, ACIError *err, sb4 dy, sb4 hr, sb4 mm, sb4 ss, sb4 fsec, ACIInterval *result);

sword ACIIntervalFromText(void *hndl, ACIError *err, const acitext *inpstring,
    size_t str_len, ACIInterval *result);

sword ACIIntervalAdd(void *hndl, ACIError *err, ACIInterval *addend1,
	ACIInterval *addend2, ACIInterval *result);

sword ACIIntervalAssign(void *hndl, ACIError *err, const ACIInterval *inpinter,
	ACIInterval *outinter);

sword ACIIntervalCheck(void *hndl, ACIError *err, const ACIInterval *interval,
	ub4 *valid);

sword ACIIntervalCompare(void *hndl, ACIError *err, ACIInterval *inter1, ACIInterval *inter2, sword *result);

sword ACIIntervalDivide(void *hndl, ACIError *err, ACIInterval *dividend, ACINumber *divisor, ACIInterval *result);

sword ACIIntervalToText(void *hndl, ACIError *err, const ACIInterval *interval,
	ub1 lfprec, ub1 fsprec, OraText *buffer, size_t buflen, size_t *resultlen);

sword ACIIntervalFromNumber(void *hndl, ACIError *err, ACIInterval *interval, 
	ACINumber *number);

sword ACIIntervalToNumber(void *hndl, ACIError *err, ACIInterval *interval, 
	ACINumber *number);

sword ACIIntervalMultiply(void  *hndl, ACIError *err, const ACIInterval *inter, 
	ACINumber *nfactor, ACIInterval *result);

sword ACIIntervalSubtract(void *hndl, ACIError *err, ACIInterval *minuend, 
	ACIInterval *subtrahend, ACIInterval *result);

sword ACIIntervalFromTZ(void *hndl, ACIError *err, const oratext *inpstring, 
	size_t len, ACIInterval *result);

sword ACIEnvCreate(ACIEnv **envhpp, ub4 mode, CONST dvoid *ctxp,
    CONST dvoid *(*malocfp)(dvoid *ctxp, size_t size),
    CONST dvoid *(*ralocfp)(dvoid *ctxp, dvoid *memptr, size_t newsize),
    CONST void(*mfreefp)(dvoid *ctxp, dvoid *memptr), size_t xtramemsz,
    dvoid **usrmempp);

sword ACIInputValidate(oratext   *str,
	ub4        strl,
	ACIError  *errhp,
	ub4        mode);

sword ACITerminate(ub4 mode);

sword ACIClientVersion(sword *major_version, sword *minor_version,
    sword *update_num, sword *patch_num, sword *port_update_num);
sword ACIServerVersion(void  *hndlp, ACIError *errhp, OraText *bufp, 
    ub4 bufsz, ub1 hndltype);

sword ACIServerRelease(void  *hndlp, ACIError *errhp, OraText *bufp,
	ub4 bufsz, ub1 hndltype, ub4 *version);

sword ACIServerRelease2(void  *hndlp, ACIError *errhp, OraText *bufp,
	ub4 bufsz, ub1 hndltype, ub4 *version, ub4 mode);

sword VersionStringToInt(OraText *bufp, ub4 *version);

sword szdb_version_str(char* des);
void __get_info(void);

sword ACITransStart(ACISvcCtx *svchp, ACIError *errhp, uword timeout, ub4 flags);

sword ACITransDetach(ACISvcCtx *svchp, ACIError *errhp, ub4 flags);

sword ACITransForget(ACISvcCtx *svchp, ACIError *errhp, ub4 flags);

sword ACITransMultiPrepare(ACISvcCtx *svchp, ub4 numBranches, ACITrans **txns, ACIError **errhp);

sword ACITransPrepare(ACISvcCtx *svchp, ACIError *errhp, ub4 flags);

sword ACIStmtGetBindInfo(ACIStmt *stmtp, ACIError *errhp, ub4 size, 
    ub4 startloc, sb4 *found, OraText *bvnp[], ub1 bvnl[], OraText *invp[], 
    ub1 inpl[], ub1 dupl[], ACIBind **hndl);

sword ACIStmtSetPieceInfo(void  *hndlp, ub4 type, ACIError *errhp, 
	const void  *bufp, ub4 *alenp, ub1 piece, 
	const void  *indp, ub2 *rcodep);

sword ACIStmtGetPieceInfo   (ACIStmt *stmtp, ACIError *errhp, 
	void  **hndlpp, ub4 *typep, ub1 *in_outp, ub4 *iterp, ub4 *idxp, ub1 *piecep);

sword ACIBulkInit(ACISvcCtx *pSvc, ACIHIMP *pImp,
				  char *schema, char *table, char *listcol, ACIError *errhp);

sword ACIBulkSetColumn(ACIHIMP *pImp, ub4 valType, 
					   void* attrValue, sb4 valLen, ACIError *errhp);

sword ACIBulkEndRow(ACIHIMP *pImp, ACIError *errhp);

sword ACIBulkExec(ACIHIMP *pImp, ACIError *errhp);

sword ACIPing(ACISvcCtx *svchp, ACIError *errhp, ub4 mode);

sword ACIBulkPrepare(ACISvcCtx *svchp, ACIBulk *bulkhp,
                  CONST char *schema, CONST char *table, 
                  CONST char *columns, ACIError *errhp);

sword ACIBulkColEntrySet(ACIBulk *bulkhp, dvoid *valuep, sb4 value_sz, 
                  ub2 dty, ACIError *errhp);

sword ACIBulkColToStream(ACIBulk *bulkhp, ACIError *errhp);

sword ACIBulkFinish(ACIBulk *bulkhp, ACIError *errhp);

void ACIEnableMultiRelease(unsigned int bOn);

sword ACIBulkGetRowid(ACIHIMP *pImp, sb4 offSet, sb4 nRows, sb4 *fetchedRows, 
                      dvoid*buffer, sb4 bufSize, ACIError *errhp);

sword ACINumberAdd(ACIError *err, const ACINumber *number1, 
                   const ACINumber *number2, ACINumber *result);

sword ACINumberSub(ACIError *err, const ACINumber *number1, 
                   const ACINumber *number2, ACINumber *result);

sword ACINumberMul(ACIError *err, const ACINumber *number1, 
                   const ACINumber *number2, ACINumber *result);

sword ACINumberDiv(ACIError *err, const ACINumber *number1, 
                   const ACINumber *number2, ACINumber *result);
sword ACINumberMod(ACIError *err, const ACINumber *number1, 
                   const ACINumber *number2, ACINumber *result);
sword ACINumberAbs(ACIError *err, const ACINumber *number, ACINumber *result);

sword ACINumberSign (ACIError *err, const ACINumber *number, sword *result);

sword ACINumberFromInt(ACIError *err, const void *inum, 
                       uword inum_length, uword inum_s_flag,
                       ACINumber *number);

sword ACINumberFromText (ACIError *err, const OraText *str, ub4 str_length,
                         const OraText *fmt, ub4 fmt_length, 
                         const OraText *nls_params, ub4 nls_p_length,
                         ACINumber *number);
void ACINumberSetZero(ACIError *err, ACINumber *number);
 
sword ACINumberCmp(ACIError *err, const ACINumber *number1, 
                   const ACINumber *number2, sword *result);

sword ACINumberCeil(ACIError *err, const ACINumber *number,  ACINumber *result);

sword ACINumberFloor(ACIError *err, const ACINumber *number, ACINumber *result);

sword ACINumberDec(ACIError *err, ACINumber *number);

sword ACINumberInc(ACIError *err, ACINumber *number);

sword ACINumberTrunc (ACIError *err, const ACINumber *number, sword decplace,
                      ACINumber *result);
sword ACINumberLn(ACIError *err, const ACINumber *number,
                  ACINumber *result);
sword ACINumberLog(ACIError *err, const ACINumber *base, const ACINumber *number,
                  ACINumber *result);
sword ACINumberPower(ACIError *err, const ACINumber *base, const ACINumber *number,
                      ACINumber *result);
sword ACINumberSqrt(ACIError *err, const ACINumber *number, ACINumber *result);
sword ACINumberExp(ACIError *err, const ACINumber *number, ACINumber *result);
sword ACINumberAssign(ACIError *err, const ACINumber *from, ACINumber *to);
sword ACINumberIsZero(ACIError *err, const ACINumber *number, 
                      int *result);
sword ACINumberNeg(ACIError *err, const ACINumber *number, ACINumber *result);
sword ACINumberFromReal(ACIError *err, const void *rnum,  uword rnum_length,
                         ACINumber *number);
sword ACINumberToInt(ACIError *err, const ACINumber *number, uword rsl_length,
                      uword rsl_flag, void *rsl);
sword ACINumberToReal(ACIError *err, const ACINumber *number, uword rsl_length,
                       void *rsl);
sword ACINumberToRealArray(ACIError *err, const ACINumber **number,
                           uword elems, uword rsl_length, void *rsl);
sword ACINumberToText(ACIError *err, const ACINumber *number, const OraText *fmt,
                       ub4 fmt_length, const OraText *nls_params, ub4 nls_p_length,
                       ub4 *buf_size, OraText *buf);
sword ACINumberIsInt(ACIError *err, const ACINumber *number, int *result);
void  ACINumberSetPi(ACIError *err, ACINumber *num);
sword ACINumberShift(ACIError *err, const ACINumber *number, const sword nDig,
                      ACINumber *result);
sword ACINumberIntPower(ACIError *err, const ACINumber *base, const sword exp,
                         ACINumber *result);
sword ACINumberRound(ACIError *err, const ACINumber *number, sword decplace,
                      ACINumber *result);
                    //<TrigonometricFunctions>
sword ACINumberSin(ACIError *err, const ACINumber *number, ACINumber *result);
sword ACINumberCos(ACIError *err, const ACINumber *number, ACINumber *result);
sword ACINumberTan(ACIError *err, const ACINumber *number, ACINumber *result);
sword ACINumberArcSin(ACIError *err, const ACINumber *number, ACINumber *result);
sword ACINumberArcCos(ACIError *err, const ACINumber *number, ACINumber *result);
sword ACINumberArcTan(ACIError *err, const ACINumber *number, ACINumber *result);
sword ACINumberArcTan2(ACIError *err, const ACINumber *number1, 
                       const ACINumber *number2,  ACINumber *result);
sword ACINumberHypSin(ACIError *err, const ACINumber *number, ACINumber *result);
sword ACINumberHypCos(ACIError *err, const ACINumber *number, ACINumber *result);
sword ACINumberHypTan(ACIError *err, const ACINumber *number, ACINumber *result);
                    //</TrigonometricFunctions>

sword ACIDirPathPrepare(ACIDirPathCtx *pDpctx, ACISvcCtx *pSvc, ACIError *errhp);

sword ACIDirPathColArrayReset(ACIDirPathColArray *pDpca, ACIError *errhp);

sword ACIDirPathStreamReset(ACIDirPathStream *pDpstr, ACIError *errhp);

sword ACIDirPathColArrayEntrySet(ACIDirPathColArray *pDpca, ACIError *errhp, 
								 ub4 rownum, ub2 colIdx, ub1 *cvalp, ub4 clen, ub1 cflg );

sword ACIDirPathColArrayToStream (ACIDirPathColArray *pDpca, ACIDirPathCtx const *pDpctx, 
								  ACIDirPathStream *pDpstr, ACIError *errhp, ub4 rowcnt, ub4 rowoff );

sword ACIDirPathLoadStream (ACIDirPathCtx *pDpctx, ACIDirPathStream *pDpstr, ACIError *errhp);

sword ACIDirPathDataSave (ACIDirPathCtx *pDpctx, ACIError *errhp, ub4 action);

sword ACIDirPathFinish(ACIDirPathCtx *pDpctx, ACIError *errhp);

sword ACIDirPathAbort(ACIDirPathCtx *pDpctx, ACIError *errhp);

sword ACIBreak(void *handlp, ACIError *errhp);

sword ACIReset(void *handlp, ACIError *errhp);

sword ACIEnvNlsCreate(ACIEnv **envhpp, ub4 mode, CONST dvoid *ctxp,
					  CONST dvoid *(*malocfp)(dvoid *ctxp, size_t size),
					  CONST dvoid *(*ralocfp)(dvoid *ctxp, dvoid *memptr, size_t newsize),
					  CONST void(*mfreefp)(dvoid *ctxp, dvoid *memptr), size_t xtramemsz,
					  dvoid **usrmempp, ub2 charset, ub2 ncharset);

sword ACINlsCharSetIdToName(dvoid *hndlp, OraText *buf, size_t buflen, ub2 id);

ub2 ACINlsCharSetNameToId(dvoid *hndlp, const OraText *name);

sword ACINlsNumericInfoGet(dvoid *hndl, ACIError *errhp, sb4 *val, ub2 item);

sword ACINlsEnvironmentVariableGet(dvoid *val, size_t size, ub2 item, ub2 charset, size_t *rsize);

sword ACINlsGetInfo(dvoid *hndl, ACIError *errhp, OraText *buf, size_t buflen, ub2 item);

sword ACINlsCharSetConvert (void *hndl, ACIError *errhp, ub2 dstid, void *dstp, 
							size_t dstlen, ub2 srcid, const void *srcp, size_t srclen,
							size_t *rsize );

sword ACINlsNameMap(void* hndl, OraText* buf, size_t buflen, const OraText* srcbuf, uword flag);

sword ACICharSetToUnicode(void  *envhp, ub2 *dst, size_t dstlen,
	const OraText *src, size_t  srclen, size_t *rsize);

sword ACIUnicodeToCharSet(void  *envhp, OraText *dst, size_t dstlen,
	const ub2 *src, size_t srclen, size_t *rsize);

ub1 ACICharSetConversionIsReplacementUsed(void  *envhp);

sword ACIRawAssignRaw(ACIEnv *env, ACIError *err, const ACIRaw *rhs, ACIRaw **lhs);

sword ACIRawAssignBytes(ACIEnv *env, ACIError *err, const ub1 *rhs, ub4 rhs_len, ACIRaw **lhs);

sword ACIRawResize(ACIEnv *env, ACIError *err, ub4 new_size, ACIRaw **raw);

ub4 ACIRawSize(ACIEnv * env, const ACIRaw *raw);

ub1 *ACIRawPtr(ACIEnv * env, const ACIRaw *raw);

sword ACIRawAllocSize(ACIEnv *env, ACIError *err, const ACIRaw *raw, ub4 *allocsize);

sword ACILastInsertId(ACIStmt *stmtp, ub1 *LastInsertId, ub2 *id_len);

sword ACIPasswordChange(ACISvcCtx *svchp, ACIError *errhp, const OraText *user_name, ub4 usernm_len, const OraText *opasswd, ub4 opasswd_len, const OraText *npasswd, ub4 npasswd_len, ub4 mode);

sword ACIJsonToTextBuffer(ACISvcCtx* svchp, ACIJson* jsond, acitext* bufp, aciub8* byte_amtp, ub4 wflags, ub2 encoding, ACIError* errhp, ub4 mode);

sword ACIJsonTextBufferParse(void* hndlp, ACIJson* jsond, void* bufp, aciub8 buf_sz, ub4 validation, ub2 encoding, ACIError* errhp, ub4 mode);

sword ACIJsonBinaryLengthGet(ACISvcCtx *svchp, ACIJson *jsond, aciub8 *byte_amtp, ACIError *errhp, ub4 mode);

sword ACIJsonToBinaryBuffer(ACISvcCtx *svchp, ACIJson *jsond, ub1 *bufp, aciub8 *byte_amtp, ACIError *errhp, ub4 mode);

sword ACIJsonClone(ACISvcCtx *svchp, ACIJson *src_jsond, ACIJson *dest_jsond, ACIError *errhp, ub4 mode);

sword ACIJsonBinaryBufferLoad(void *hndlp, ACIJson *jsond, ub1 *bufp, aciub8 buf_sz, ACIError *errhp, ub4 mode);

sword ACIRowidToChar(ACIRowid* rowidDesc, acitext* outbfp, ub2* outbflp, ACIError* errhp);

sword ACIDBStartup(ACISvcCtx *svchp, ACIError *errhp, ACIAdmin *admhp, ub4 mode, ub4 flags);

sword ACIDBShutdown(ACISvcCtx *svchp, ACIError *errhp, ACIAdmin *admhp, ub4 mode);

sword ACIStringAllocSize(ACIEnv *env, ACIError *err, const ACIString *vs, ub4 *allocsize);

sword ACIStringAssign(ACIEnv *env, ACIError *err, const ACIString *rhs, ACIString **lhs);

sword ACIStringAssignText(ACIEnv *env, ACIError *err, const OraText *rhs, ub4 rhs_len, ACIString **lhs);

text *ACIStringPtr(ACIEnv *env, const ACIString *vs);

sword ACIStringResize(ACIEnv *env, ACIError *err, ub4 new_size, ACIString **str);

ub4   ACIStringSize(ACIEnv *env,const ACIString *vs);

sword ACIAQDeq(ACISvcCtx *svchp, ACIError *errhp, OraText *queue_name, ACIAQDeqOptions *dequeue_options, ACIAQMsgProperties *message_properties,
	ACIType *payload_tdo, void **payload, void **payload_ind, ACIRaw **msgid, ub4 flags);

sword ACIAQDeqArray(ACISvcCtx *svchp, ACIError *errhp, OraText *queue_name, ACIAQDeqOptions *deqopt, ub4 *iters, ACIAQMsgProperties **msgprop, ACIType *payload_tdo,
	void **payload, void **payload_ind, ACIRaw **msgid, void *ctxp,
	ACICallbackAQDeq(cbfp)
	(
		void          *ctxp,
		void         **payload,
		void         **payload_ind
		),
	ub4 flags);

sword ACIAQEnq(ACISvcCtx *svchp, ACIError *errhp, OraText *queue_name, ACIAQEnqOptions *enqueue_options, ACIAQMsgProperties *message_properties,
	ACIType *payload_tdo, void **payload, void **payload_ind, ACIRaw **msgid, ub4 flags);

sword ACIAQEnqArray(ACISvcCtx *svchp, ACIError *errhp, OraText *queue_name, ACIAQEnqOptions *enqopt, ub4 *iters, ACIAQMsgProperties **msgprop, 
	ACIType *payload_tdo, void **payload, void **payload_ind, ACIRaw **msgid, void *ctxp,
	ACICallbackAQEnq(cbfp)
	(
		void         *ctxp,
		void        **payload,
		void        **payload_ind
		),
	ub4 flags);

sword ACIAQListen2(ACISvcCtx *svchp, ACIError *errhp, ACIAQAgent **agent_list, ub4 num_agents, ACIAQListenOpts *lopts, ACIAQAgent **agent, ACIAQLisMsgProps *lmops, ub4 flags);

sword ACIAQListen(ACISvcCtx *svchp, ACIError *errhp, ACIAQAgent **agent_list, ub4 num_agents, sb4 wait, ACIAQAgent **agent, ub4 flags);

sword ACISodaBulkInsert(ACISvcCtx *svchp, ACISodaColl *collection, ACISodaDoc **documentarray, ub4 arraylen, ACISodaOutputOptions *opoptns, ACIError *errhp, ub4 mode);

sword ACISodaBulkInsertAndGet(ACISvcCtx *svchp, ACISodaColl *collection, ACISodaDoc **documentarray, ub4 arraylen, ACISodaOutputOptions *opoptns, ACIError *errhp, ub4 mode);

sword ACISodaBulkInsertAndGetWithOpts(ACISvcCtx *svchp, ACISodaColl *collection, ACISodaDoc **documentarray, ub4 arraylen, ACISodaOperationOptions *oproptns,
	ACISodaOutputOptions *opoptns, ACIError *errhp, ub4 mode);

sword ACISodaBulkInsertAndGetWithCont(ACISvcCtx *svchp, ACISodaColl *collection, void **contentStrings, ub4 *contentStringLengths, OraText **keys, ub4 *keyLengths, ub4 arrayLength,
	ub4 docFlags, ACISodaDoc **documents, ACISodaOutputOptions *opoptns, ACIError *errhp, ub4 mode);

sword ACISodaBulkInsertWithCtnt(ACISvcCtx *svchp, ACISodaColl *collection, void **contentStrings, ub4 *contentStringLengths, OraText **keys, ub4 *keyLengths,
	ub4 arrayLength, ub4 docFlags, ACISodaOutputOptions *opoptns, ACIError *errhp, ub4 mode);

sword ACISodaCollCreate(ACISvcCtx *svchp, const OraText *collname, ub4 collnamelen, ACISodaColl **collection, ACIError *errhp, ub4 mode);

sword ACISodaCollCreateWithMetadata(ACISvcCtx *svchp, const OraText *collname, ub4 collnamelen, OraText *metadata, ub4 metadatalen, ACISodaColl **collection, 
	ACIError *errhp, ub4 mode);

sword ACISodaCollDrop(ACISvcCtx *svchp, ACISodaColl *coll, ub4 *isDropped, ACIError *errhp, ub4 mode);

sword ACISodaCollGetNext(ACISvcCtx *svchp, const ACISodaCollCursor *cur, ACISodaColl **coll, ACIError *errhp, ub4 mode);

sword ACISodaCollList(ACISvcCtx *svchp, const OraText *startname, ub4 stnamelen, ACISodaCollCursor **cur, ACIError *errhp, ub4 mode);

sword ACISodaCollOpen(ACISvcCtx *svchp, const OraText *collname, ub4 collnamelen, ACISodaColl **coll, ACIError *errhp, ub4 mode);

sword ACISodaDataGuideGet(ACISvcCtx *svchp, const ACISodaColl *collection, ub4 docFlags, ACISodaDoc **doc, ACIError *errhp, ub4 mode);

sword ACISodaDataGuideGetWithOpts(ACISvcCtx *svchp, const ACISodaColl *collection, ACISodaOperationOptions *optns, ub4 format, ub4 flags, ub4 docFlags, 
	ACISodaDoc **doc, ACIError *errhp, ub4 mode);

sword ACISodaAsOfTimestampGet(ACISvcCtx *svchp, void *tstamp, ub4 *tstampLen, ACIError *errhp, ub4 mode);

sword ACISodaAsOfScnGet(ACISvcCtx *svchp, ub8 *scn, ACIError *errhp, ub4 mode);

sword ACISodaDocCount(ACISvcCtx *svchp, const ACISodaColl *coll, const ACISodaOperationOptions *optns, ub8 *numdocs, ACIError *errhp, ub4 mode);

sword ACISodaDocCountWithFilter(ACISvcCtx *svchp, const ACISodaColl *coll, const OraText *filterSpec, ub4 filterSpecLen, ub8 *numdocs, ACIError *errhp, ub4 mode);

sword ACISodaDocCreate(ACIEnv *envhp, const void *content, ub4 contentLength, ub4 docFlags, ACISodaDoc **document, ACIError *errhp, ub4 mode);

sword ACISodaDocCreateWithKey(ACIEnv *envhp, const void *content, ub4 contentLength, const OraText *key, ub4 keylen, ub4 docFlags, ACISodaDoc **document, 
	ACIError *errhp, ub4 mode);

sword ACISodaDocCreateWithKeyAndMType(ACIEnv *envhp, const void *content, ub4 contentLength, const OraText *key, ub4 keylen, const OraText *mediaType, 
	ub4 mediaTypeLength, ub4 docFlags, ACISodaDoc **document, ACIError *errhp, ub4 mode);

sword ACISodaDocGetNext(ACISvcCtx *svchp, const ACISodaDocCursor *cursor, ACISodaDoc **doc, ACIError *errhp, ub4 mode);

sword ACISodaFind(ACISvcCtx *svchp, const ACISodaColl *coll, const ACISodaOperationOptions *findOptions, ub4 docFlags, ACISodaDocCursor **cursor, ACIError *errhp, ub4 mode);

sword ACISodaFindOne(ACISvcCtx *svchp, const ACISodaColl *coll, const ACISodaOperationOptions  *findOptions, ub4 docFlags, ACISodaDoc **doc, ACIError *errhp, ub4 mode);

sword ACISodaFindOneWithKey(ACISvcCtx *svchp, const ACISodaColl *coll, const OraText *key, ub4 keylen, ub4 docFlags, ACISodaDoc **doc, ACIError *errhp, ub4 mode);

sword ACISodaIndexCreate(ACISvcCtx *svchp, const ACISodaColl *coll, const OraText *indexspec, ub4 speclen, ACIError *errhp, ub4 mode);

sword ACISodaIndexGet(ACISvcCtx *svchp, const ACISodaColl *collection, OraText *indexName, ub4 indexNameLen, OraText *schemaName,
	ub4 schemaNameLen, ub4 flags, ACIString **index, ACIError *errhp, ub4 mode);

sword ACISodaIndexList(ACISvcCtx *svchp, const ACISodaColl *collection, ub4 flags, ACIColl **indexList, ACIError *errhp, ub4 mode);

sword ACISodaIndexDrop(ACISvcCtx *svchp, OraText *indexname, ub4 indexnamelen, ub4 *isDropped, ACIError *errhp, ub4 mode);

sword ACISodaInsert(ACISvcCtx *svchp, ACISodaColl *collection, ACISodaDoc *document, ACIError *errhp, ub4 mode);

sword ACISodaInsertAndGet(ACISvcCtx *svchp, ACISodaColl *collection, ACISodaDoc **document, ACIError *errhp, ub4 mode);

sword ACISodaInsertAndGetWithOpts(ACISvcCtx *svchp, ACISodaColl *collection, ACISodaDoc **document, ACISodaOperationOptions *oproptns, ACIError *errhp, ub4 mode);

sword ACISodaInsertAndGetWithCtnt(ACISvcCtx *svchp, ACISodaColl *collection, const OraText *key, ub4 keyLength, const void *content,
	ub4 contentLength, ub4 docFlags, ACISodaDoc **document, ACIError *errhp, ub4 mode);

sword ACISodaInsertWithCtnt(ACISvcCtx *svchp, ACISodaColl *collection, const OraText *key, ub4 keyLength, const void *content, 
	ub4 contentLength, ub4 docFlags, ACIError *errhp, ub4 mode);

sword ACISodaRemove(ACISvcCtx *svchp, const ACISodaColl *coll, const ACISodaOperationOptions *optns, ub8 *removeCount, ACIError *errhp, ub4 mode);

sword ACISodaRemoveOneWithKey(ACISvcCtx *svchp, const ACISodaColl *coll, const OraText *key, ub4 keylength, ub4 *isRemoved, ACIError *errhp, ub4 mode);

sword ACISodaReplOne(ACISvcCtx *svchp, const ACISodaColl *coll, const ACISodaOperationOptions *optns, ACISodaDoc *document, ub4 *isReplaced, ACIError *errhp, ub4 mode);

sword ACISodaReplOneAndGet(ACISvcCtx *svchp, const ACISodaColl *coll, const ACISodaOperationOptions *optns, ACISodaDoc **document, ub4 *isReplaced, ACIError *errhp, ub4 mode);

sword ACISodaReplOneAndGetWithCtnt(ACISvcCtx *svchp, const ACISodaColl *coll, const ACISodaOperationOptions *optns, const void *content, 
	ub4 contentLen, ub4 docFlags, ACISodaDoc **document, ub4 *isReplaced, ACIError *errhp, ub4 mode);

sword ACISodaReplOneAndGetWithKey(ACISvcCtx *svchp, const ACISodaColl *coll, const OraText *key, ub4 keylength, ACISodaDoc **document, ub4 *isReplaced, ACIError *errhp, ub4 mode);

sword ACISodaReplOneWithCtnt(ACISvcCtx *svchp, const ACISodaColl *coll, const ACISodaOperationOptions *optns, const void *content, ub4 contentLength, 
	ub4 docFlags, ub4 *isReplaced, ACIError *errhp, ub4 mode);

sword ACISodaReplOneWithKey(ACISvcCtx *svchp, const ACISodaColl *coll, const OraText *key, ub4 keylength, ACISodaDoc *document, ub4 *isReplaced, ACIError *errhp, ub4 mode);

sword ACISodaSave(ACISvcCtx *svchp, ACISodaColl *collection, ACISodaDoc *document, ACIError *errhp, ub4 mode);

sword ACISodaSaveAndGet(ACISvcCtx *svchp, ACISodaColl *collection, ACISodaDoc **document, ACIError *errhp, ub4 mode);

sword ACISodaSaveAndGetWithOpts(ACISvcCtx *svchp, ACISodaColl *collection, ACISodaDoc **document, ACISodaOperationOptions *oproptns, ACIError *errhp, ub4 mode);

sword ACISodaSaveWithCtnt(ACISvcCtx *svchp, ACISodaColl *collection, const OraText *key, ub4 keylength, const void *content, ub4 contentlen, 
	ub4 docFlags, ACIError *errhp, ub4 mode);

sword ACISodaSaveAndGetWithCont(ACISvcCtx *svchp, ACISodaColl *collection, const OraText *key, ub4 keylength, const void *content, ub4 contentlen,
	ub4 docFlags, ACISodaDoc **document, ACIError *errhp, ub4 mode);

sword ACISodaCollTruncate(ACISvcCtx *svchp, const ACISodaColl *collection, ACIError *errhp, ub4 mode);

sword ACISodaOperKeysSet(const ACISodaOperationOptions *operhp, OraText **keysArray, ub4 *lengthsArray, ub4 count, ACIError *errhp, ub4 mode);

sword ACIRowidToChar(ACIRowid* rowidDesc, acitext* outbfp, ub2* outbflp, ACIError* errhp);

sword ACIDBStartup(ACISvcCtx* svchp, ACIError* errhp, ACIAdmin* admhp, ub4 mode, ub4 flags);

sword ACIDBShutdown(ACISvcCtx* svchp, ACIError* errhp, ACIAdmin* admhp, ub4 mode);

sword ACICollGetElem(ACIEnv* env, ACIError* err, const ACIColl* coll,
    sb4 index, sb4 * exists, void** elem,
    void** elemind);

sword ACICollAppend(ACIEnv* env, ACIError* err, const void* elem,
    const void* elemind, ACIColl* coll);

sword ACICollTrim(ACIEnv* env, ACIError* err, sb4 trim_num,
    ACIColl* coll);

sb4 ACICollMax(ACIEnv* env, const ACIColl* coll);

sword ACICollSize(ACIEnv* env, ACIError* err, const ACIColl* coll,
    sb4* size);

sword ACICollIsLocator(ACIEnv* env, ACIError* err, const ACIColl* coll,
    sb4* result);

sword ACICollGetElemArray(ACIEnv* env, ACIError* err, const ACIColl* coll,
    sb4 index, sb4* exists, void** elem,
    void** elemind, uword* nelems);

sword ACICollAssignElem(ACIEnv* env, ACIError* err, sb4 index,
    const void* elem,
    const void* elemind, ACIColl* coll);

sword ACICollAssign(ACIEnv* env, ACIError* err, const ACIColl* rhs,
    ACIColl* lhs);

sword ACITableFirst(ACIEnv* env, ACIError* err, const ACITable* tbl,
    sb4* index);

sword ACITableSize(ACIEnv* env, ACIError* err, const ACITable* tbl,
    sb4* size);

sword ACITableNext(ACIEnv* env, ACIError* err, sb4 index,
    const ACITable* tbl, sb4* next_index,
    sb4* exists);

sword ACITableDelete(ACIEnv* env, ACIError* err, sb4 index,
    ACITable* tbl);

sword ACITableExists(ACIEnv* env, ACIError* err, const ACITable* tbl,
    sb4 index, sb4* exists);

sword ACITableLast(ACIEnv* env, ACIError* err, const ACITable* tbl,
    sb4* index);

sword ACITablePrev(ACIEnv* env, ACIError* err, sb4 index,
    const ACITable* tbl, sb4* prev_index,
    sb4* exists);

sword ACIObjectNew(ACIEnv* env, ACIError* err, const ACISvcCtx* svc,
    ACITypeCode typecode, ACIType* tdo, void* table,
    ACIDuration duration, sb4 value,
    void** instance);

sword ACIObjectUnpin(ACIEnv* env, ACIError* err, void* object);

sword ACIObjectUnmark(ACIEnv* env, ACIError* err, void* object);

sword ACIObjectFree(ACIEnv* env, ACIError* err, void* instance,
    ub2 flags);

sword ACIObjectGetAttr(ACIEnv* env, ACIError* err, void* instance,
    void* null_struct, struct ACIType* tdo,
    const acitext** names, const ub4* lengths,
    const ub4 name_count, const ub4* indexes,
    const ub4 index_count, ACIInd* attr_null_status,
    void** attr_null_struct, void** attr_value,
    struct ACIType** attr_tdo);

sword ACIObjectSetAttr(ACIEnv* env, ACIError* err, void* instance,
    void* null_struct, struct ACIType* tdo,
    const acitext** names, const ub4* lengths,
    const ub4 name_count, const ub4* indexes,
    const ub4 index_count, const ACIInd null_status,
    const void* attr_null_struct, const void* attr_value);

sword ACIObjectPin(ACIEnv* env, ACIError* err, ACIRef* object_ref,
    ACIComplexObject* corhdl, ACIPinOpt pin_option,
    ACIDuration pin_duration,
    ACILockOpt lock_option, void** object);

sword ACIObjectGetInd(ACIEnv* env, ACIError* err, void* instance,
    void** null_struct);

sword ACIObjectGetTypeRef(ACIEnv* env, ACIError* err, void* instance,
    ACIRef* type_ref);

sword ACIObjectArrayPin(ACIEnv* env, ACIError* err, ACIRef** ref_array,
    ub4 array_size, ACIComplexObject** cor_array,
    ub4 cor_array_size, ACIPinOpt pin_option,
    ACIDuration pin_duration, ACILockOpt lock,
    void** obj_array, ub4* pos);

sword ACIObjectCopy(ACIEnv* env, ACIError* err, const ACISvcCtx* svc,
    void* source, void* null_source,
    void* target, void* null_target, ACIType* tdo,
    ACIDuration duration, ub1 option);

sword ACIObjectExists(ACIEnv* env, ACIError* err, void* ins, sb4* exist);

sword ACIObjectFlush(ACIEnv* env, ACIError* err, void* object);

sword ACIObjectGetObjectRef(ACIEnv* env, ACIError* err, void* object,
    ACIRef* object_ref);

sword ACIObjectGetProperty(ACIEnv* envh, ACIError* errh, const void* obj,
    ACIObjectPropId propertyId,
    void* property, ub4* size);

sword ACIObjectIsDirty(ACIEnv* env, ACIError* err, void* ins,
    sb4* dirty);

sword ACIObjectIsLocked(ACIEnv* env, ACIError* err, void* ins,
    sb4* lock);

sword ACIObjectIsLoaded(ACIEnv* env, ACIError* err, void* ins,
    sb4* load);

sword ACIObjectLock(ACIEnv* env, ACIError* err, void* object);

sword ACIObjectLockNoWait(ACIEnv* env, ACIError* err, void* object);

sword ACIObjectMarkDelete(ACIEnv* env, ACIError* err, void* instance);

sword ACIObjectMarkDeleteByRef(ACIEnv* env, ACIError* err,
    ACIRef* object_ref);

sword ACIObjectMarkUpdate(ACIEnv* env, ACIError* err, void* object);

sword ACIObjectPinCountReset(ACIEnv* env, ACIError* err, void* object);

sword ACIObjectPinTable(ACIEnv* env, ACIError* err, const ACISvcCtx* svc,
    const oratext* schema_name,
    ub4 s_n_length, const oratext* object_name, ub4 o_n_length,
    const ACIRef* scope_obj_ref, ACIDuration pin_duration,
    void** object);

sword ACIObjectRefresh(ACIEnv* env, ACIError* err, void* object);

sword ACIObjectUnmarkByRef(ACIEnv* env, ACIError* err, ACIRef* ref);

void ACIRefClear(ACIEnv* env, ACIRef* ref);

sword ACIRefAssign(ACIEnv* env, ACIError* err, const ACIRef* source,
	ACIRef** target);

sb4 ACIRefIsEqual(ACIEnv* env, const ACIRef* x, const ACIRef* y);

sb4 ACIRefIsNull(ACIEnv* env, const ACIRef* ref);

ub4 ACIRefHexSize(ACIEnv* env, const ACIRef* ref);

sword ACIRefFromHex(ACIEnv* env, ACIError* err, const ACISvcCtx* svc,
	const acitext* hex, ub4 length, ACIRef** ref);

sword ACIRefToHex(ACIEnv* env, ACIError* err, const ACIRef* ref,
    acitext* hex, ub4* hex_length);

sword ACITypeByName(ACIEnv* env, ACIError* err, const ACISvcCtx* svc,
    const acitext* schema_name, ub4 s_length,
    const acitext* type_name, ub4 t_length,
    const acitext* version_name, ub4 v_length,
    ACIDuration pin_duration, ACITypeGetOpt get_option,
    ACIType** tdo);

sword ACITypeByFullName(ACIEnv* env, ACIError* err, const ACISvcCtx* svc,
    const acitext* full_type_name,
    ub4 full_type_name_length,
    const acitext* version_name, ub4 version_name_length,
    ACIDuration pin_duration, ACITypeGetOpt get_option,
    ACIType** tdo);

sword ACITypeByRef(ACIEnv* env, ACIError* err,
    const ACIRef* type_ref, ACIDuration pin_duration,
    ACITypeGetOpt get_option, ACIType** tdo);

sword ACITypeArrayByFullName(ACIEnv* env, ACIError* err, const ACISvcCtx* svc,
    ub4 array_len,
    const acitext* full_type_name[],
    ub4 full_type_name_length[],
    const acitext* version_name[],
    ub4 version_name_length[],
    ACIDuration pin_duration,
    ACITypeGetOpt get_option, ACIType** tdo);

sword ACITypeArrayByName(ACIEnv* env, ACIError* err, const ACISvcCtx* svc,
    ub4 array_len,
    const acitext* schema_name[], ub4 s_length[],
    const acitext* type_name[], ub4 t_length[],
    const acitext* version_name[], ub4 v_length[],
    ACIDuration pin_duration,
    ACITypeGetOpt get_option, ACIType** tdo);

sword   ACITypeArrayByRef(ACIEnv* env, ACIError* err,
    ub4 array_len, const ACIRef** type_ref,
    ACIDuration pin_duration,
    ACITypeGetOpt get_option, ACIType** tdo);

sword ACITypeBeginCreate(ACISvcCtx* svchp, ACIError* errhp, ACITypeCode tc,
    ACIDuration dur, ACIType** type);

sword ACITypeEndCreate(ACISvcCtx* svchp, ACIError* errhp, ACIType* type);

acitext* ACITypePackage(ACIEnv* env, ACIError* err, const ACIType* tdo,
    ub4* n_length);

sword ACITypeSetBuiltin(ACISvcCtx* svchp, ACIError* errhp, ACIType* type,
    ACIParam* builtin_info);

sword ACITypeSetCollection(ACISvcCtx* svchp, ACIError* errhp, ACIType* type,
    ACIParam* collelem_info, ub4 coll_count);

sword ACITypeAddAttr(ACISvcCtx* svchp, ACIError* errhp, ACIType* type,
    const oratext* a_name, ub4 a_length,
    ACIParam* attr_info);

ub4 ACITypeAttrs(ACIEnv* env, ACIError* err, const ACIType* tdo);

ACITypeCode ACITypeCollTypeCode(ACIEnv* env, ACIError* err,
    const ACIType* tdo);

ACITypeCode ACITypeTypeCode(ACIEnv* env, ACIError* err,
	const ACIType* tdo);

acitext* ACITypeName(ACIEnv* env, ACIError* err, const ACIType* tdo,
    ub4* n_length);

ub4 ACITypeMethods(ACIEnv* env, ACIError* err, const ACIType* tdo);

sword ACITypeIterNew(ACIEnv* env, ACIError* err, ACIType* tdo,
    ACITypeIter** iterator_ort);

sword ACITypeIterFree(ACIEnv* env, ACIError* err, ACITypeIter
    * iterator_ort);

sword ACITypeIterSet(ACIEnv* env, ACIError* err, ACIType* tdo,
    ACITypeIter* iterator_ort);

sword ACITypeAttrNext(ACIEnv* env, ACIError* err,
    ACITypeIter* iterator_ort, ACITypeElem** elem);

acitext* ACITypeElemName(ACIEnv* env, ACIError* err,
    const ACITypeElem* elem, ub4* n_length);

ACITypeCode ACITypeElemTypeCode(ACIEnv* env, ACIError* err,
    const ACITypeElem* elem);

ub4 ACITypeElemLength(ACIEnv* env, ACIError* err,
    const ACITypeElem* elem);

sword ACITypeElemType(ACIEnv* env, ACIError* err, const ACITypeElem* elem,
    ACIType** elem_tdo);

sword ACITypeCollSize(ACIEnv* env, ACIError* err, const ACIType* tdo,
    ub4* num_elems);

sword ACITypeAttrByName(ACIEnv* env, ACIError* err, const ACIType* tdo,
    const acitext* name, ub4 n_length,
    ACITypeElem** elem);

sword ACITypeCollExtTypeCode(ACIEnv* env, ACIError* err,
    const ACIType* tdo, ACITypeCode* sqt_code);

sword ACITypeCollElem(ACIEnv* env, ACIError* err, const ACIType* tdo,
    ACITypeElem** element);

sword ACIIterCreate(ACIEnv* env, ACIError* err, const ACIColl* coll,
    ACIIter** itr);

sword ACIIterNext(ACIEnv* env, ACIError* err, ACIIter* itr,
    void** elem, void** elemind, sb4* eoc);

sword ACIIterDelete(ACIEnv* env, ACIError* err, ACIIter** itr);

sword ACIIterGetCurrent(ACIEnv* env, ACIError* err, const ACIIter* itr,
    void** elem, void** elemind);

sword ACIIterInit(ACIEnv* env, ACIError* err, const ACIColl* coll,
    ACIIter* itr);

sword ACIIterPrev(ACIEnv* env, ACIError* err, ACIIter* itr,
    void** elem, void** elemind, sb4* boc);

sword ACICacheFlush(ACIEnv* env, ACIError* err, const ACISvcCtx* svc,
    void* context, ACIRef* (*get)(void* context, ub1* last),
    ACIRef** ref);

sword ACICacheFree(ACIEnv* env, ACIError* err, const ACISvcCtx* svc);

sword ACICacheRefresh(ACIEnv* env, ACIError* err, const ACISvcCtx* svc,
    ACIRefreshOpt option, void* context,
    ACIRef* (*get)(void* context), ACIRef** ref);

sword ACICacheUnmark(ACIEnv* env, ACIError* err, const ACISvcCtx* svc);

sword ACICacheUnpin(ACIEnv* env, ACIError* err, const ACISvcCtx* svc);

sword ACIStmtGetNextResult(ACIStmt *stmthp, ACIError *errhp, void **result, ub4 *rtype, ub4 mode);

sword ACIThreadClose(void *hndl, ACIError *err, ACIThreadHandle *tHnd);

sword ACIThreadCreate(void *hndl, ACIError *err, void(*start) (void *), void *arg, ACIThreadId *tid, ACIThreadHandle *tHnd);

sword ACIThreadHandleGet(void *hndl, ACIError *err, ACIThreadHandle *tHnd);

sword ACIThreadHndDestroy(void *hndl, ACIError *err, ACIThreadHandle **thnd);

sword ACIThreadHndInit(void *hndl, ACIError *err, ACIThreadHandle **thnd);

sword ACIThreadIdDestroy(void *hndl, ACIError *err, ACIThreadId **tid);

sword ACIThreadIdGet(void *hndl, ACIError *err, ACIThreadId *tid);

sword ACIThreadIdInit(void *hndl, ACIError *err, ACIThreadId **tid);

sword ACIThreadIdNull(void *hndl, ACIError *err, ACIThreadId *tid, ub4 *result);

sword ACIThreadIdSame(void *hndl, ACIError *err, ACIThreadId *tid1, ACIThreadId *tid2, ub4 *result);

sword ACIThreadIdSet(void *hndl, ACIError *err, ACIThreadId *tidDest, ACIThreadId *tidSrc);

sword ACIThreadIdSetNull(void *hndl, ACIError *err, ACIThreadId *tid);

sword ACIThreadInit(void *hndl, ACIError *err);

ub4 ACIThreadIsMulti();

sword ACIThreadJoin(void *hndl, ACIError *err, ACIThreadHandle *tHnd);

sword ACIThreadKeyDestroy(void *hndl, ACIError *err, ACIThreadKey **key);

sword ACIThreadKeyGet(void *hndl, ACIError *err, ACIThreadKey *key, void **pValue);

sword ACIThreadKeyInit(void *hndl, ACIError *err, ACIThreadKey **key, ACIThreadKeyDestFunc destFn);

sword ACIThreadKeySet(void *hndl, ACIError *err, ACIThreadKey *key, void *value);

sword ACIThreadMutexAcquire(void *hndl, ACIError *err, ACIThreadMutex *mutex);

sword ACIThreadMutexDestroy(void *hndl, ACIError *err, ACIThreadMutex **mutex);

sword ACIThreadMutexInit(void *hndl, ACIError *err, ACIThreadMutex **mutex);

sword ACIThreadMutexRelease(void *hndl, ACIError *err, ACIThreadMutex *mutex);

void ACIThreadProcessInit();

sword ACIThreadTerm(void *hndl, ACIError *err);

sword ACIMemoryAlloc(void *hndl, ACIError *err, void **mem, ACIDuration dur, ub4 size, ub4 flags);

sword ACIMemoryFree(void *hndl, ACIError *err, void *mem);

sword ACIMemoryResize(void *hndl, ACIError *err, void **mem, ub4 newsize, ub4 flags);