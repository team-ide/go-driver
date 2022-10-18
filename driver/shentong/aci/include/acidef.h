#pragma once
//Functions
#define OCIInitialize                 ACIInitialize
#define OCIHandleAlloc                ACIHandleAlloc
#define OCIServerAttach               ACIServerAttach
#define OCIAttrSet                    ACIAttrSet
#define OCIAttrGet                    ACIAttrGet
#define OCISessionBegin               ACISessionBegin
#define OCISessionEnd                 ACISessionEnd
#define OCIStmtPrepare                ACIStmtPrepare
#define OCIStmtPrepare2               ACIStmtPrepare2
#define OCIDefineByPos                ACIDefineByPos
#define OCIDefineByPos2               ACIDefineByPos2
#define OCIDefineArrayOfStruct        ACIDefineArrayOfStruct
#define OCIDefineDynamic			  ACIDefineDynamic
#define OCIDefineObject				  ACIDefineObject
#define OCIStmtExecute                ACIStmtExecute
#define OCIStmtFetch                  ACIStmtFetch
#define OCIStmtFetch2                 ACIStmtFetch2
#define OCIStmtGetNextResult		  ACIStmtGetNextResult
#define OCIHandleFree                 ACIHandleFree
#define OCIErrorGet                   ACIErrorGet
#define OCIEnvInit                    ACIEnvInit
#define OCIBindByPos                  ACIBindByPos
#define OCIBindObject				  ACIBindObject
#define OCIBindByPos2                 ACIBindByPos2
#define OCIBindDynamic				  ACIBindDynamic
#define OCIBindArrayOfStruct          ACIBindArrayOfStruct
#define OCIParamGet                   ACIParamGet
#define OCIEnvCreate                  ACIEnvCreate
#define OCIStmtRelease                ACIStmtRelease
#define OCILobGetLength               ACILobGetLength
#define OCILobRead                    ACILobRead
#define OCILobWrite                   ACILobWrite
#define OCILobFileGetName             ACILobFileGetName
#define OCILobFileExists              ACILobFileExists
#define OCILobFileOpen                ACILobFileOpen
#define OCILobFileIsOpen              ACILobFileIsOpen
#define OCILobFileClose               ACILobFileClose
#define OCILobErase                   ACILobErase
#define OCILobErase2                  ACILobErase2
#define OCILobTrim                    ACILobTrim
#define OCILobCreateTemporary		  ACILobCreateTemporary
#define OCILobFreeTemporary		      ACILobFreeTemporary
#define OCILobIsTemporary			  ACILobIsTemporary
#define OCILobFileSetName             ACILobFileSetName
#define OCILobLocatorIsInit           ACILobLocatorIsInit
#define OCILobGetLength2			  ACILobGetLength2
#define OCILobTrim2                   ACILobTrim2
#define OCILobWrite2				  ACILobWrite2
#define OCILobRead2                   ACILobRead2
#define OCILobWriteAppend			  ACILobWriteAppend
#define OCILobWriteAppend2			  ACILobWriteAppend2
#define OCILobCharSetId				  ACILobCharSetId
#define OCILobCharSetForm			  ACILobCharSetForm
#define OCILobOpen					  ACILobOpen
#define OCILobClose					  ACILobClose
#define OCILobIsOpen				  ACILobIsOpen
#define OCILobAppend				  ACILobAppend
#define OCILobAssign				  ACILobAssign
#define OCILobLocatorAssign			  ACILobLocatorAssign
#define OCILobIsEqual				  ACILobIsEqual
#define OCILobCopy					  ACILobCopy
#define OCILobCopy2					  ACILobCopy2
#define OCILobLoadFromFile			  ACILobLoadFromFile
#define OCILobLoadFromFile2			  ACILobLoadFromFile2
#define OCILobFileCloseAll			  ACILobFileCloseAll
#define OCILobEnableBuffering		  ACILobEnableBuffering
#define OCILobDisableBuffering		  ACILobDisableBuffering
#define OCILobFlushBuffer			  ACILobFlushBuffer
#define OCIDurationBegin			  ACIDurationBegin
#define OCIDurationEnd				  ACIDurationEnd
#define OCILobGetChunkSize			  ACILobGetChunkSize
#define OCILobGetStorageLimit		  ACILobGetStorageLimit
#define OCIServerDataLengthGet		  ACIServerDataLengthGet
#define OCITransRollback              ACITransRollback
#define OCITransCommit                ACITransCommit
#define OCIDateAddDays                ACIDateAddDays
#define OCIDateAddMonths              ACIDateAddMonths
#define OCIDateAssign                 ACIDateAssign
#define OCIDateCheck                  ACIDateCheck
#define OCIDateCompare                ACIDateCompare
#define OCIDateDaysBetween            ACIDateDaysBetween
#define OCIDateFromText               ACIDateFromText
#define OCIDateGetDate                ACIDateGetDate
#define OCIDateGetTime                ACIDateGetTime
#define OCIDateLastDay                ACIDateLastDay
#define OCIDateNextDay                ACIDateNextDay
#define OCIDateSetDate                ACIDateSetDate
#define OCIDateSetTime                ACIDateSetTime
#define OCIDateTimeCheck              ACIDateTimeCheck
#define OCIDateTimeAssign             ACIDateTimeAssign
#define OCIDateTimeConvert            ACIDateTimeConvert
#define OCIDateTimeCompare            ACIDateTimeCompare
#define OCIDateTimeFromText           ACIDateTimeFromText
#define OCIDateTimeSysTimeStamp       ACIDateTimeSysTimeStamp
#define OCIDateTimeSubtract           ACIDateTimeSubtract
#define OCIDateTimeConstruct          ACIDateTimeConstruct
#define OCIDateTimeGetDate            ACIDateTimeGetDate
#define OCIDateTimeGetTime            ACIDateTimeGetTime
#define OCIDateTimeToText             ACIDateTimeToText
#define OCIDateTimeGetTimeZoneName	  ACIDateTimeGetTimeZoneName
#define OCIDateTimeGetTimeZoneOffset  ACIDateTimeGetTimeZoneOffset
#define OCIDateTimeIntervalAdd		  ACIDateTimeIntervalAdd
#define OCIDateTimeIntervalSub		  ACIDateTimeIntervalSub
#define OCIDateTimeToArray			  ACIDateTimeToArray
#define OCIDateTimeFromArray		  ACIDateTimeFromArray
#define OCIDateDaysSecondsBetween     ACIDateDaysSecondsBetween
#define OCIDateZoneToZone			  ACIDateZoneToZone
#define OCIDateSysDate                ACIDateSysDate
#define OCIDateToText                 ACIDateToText
#define OCIIntervalGetDaySecond       ACIIntervalGetDaySecond
#define OCIIntervalGetYearMonth		  ACIIntervalGetYearMonth
#define OCIIntervalSetDaySecond       ACIIntervalSetDaySecond
#define OCIIntervalSetYearMonth		  ACIIntervalSetYearMonth
#define OCIIntervalFromText           ACIIntervalFromText
#define OCIIntervalAdd				  ACIIntervalAdd
#define OCIIntervalAssign			  ACIIntervalAssign
#define OCIIntervalCheck			  ACIIntervalCheck
#define OCIIntervalCompare			  ACIIntervalCompare
#define OCIIntervalDivide			  ACIIntervalDivide
#define OCIIntervalToText			  ACIIntervalToText
#define OCIIntervalFromNumber         ACIIntervalFromNumber
#define OCIIntervalToNumber			  ACIIntervalToNumber
#define OCIIntervalMultiply			  ACIIntervalMultiply
#define OCIIntervalSubtract			  ACIIntervalSubtract
#define OCIIntervalFromTZ			  ACIIntervalFromTZ
#define OCITerminate				  ACITerminate
#define OCIInputValidate			  ACIInputValidate
#define OCIJsonBinaryLengthGet        ACIJsonBinaryLengthGet
#define OCIJsonToBinaryBuffer		  ACIJsonToBinaryBuffer
#define OCIJsonToTextBuffer			  ACIJsonToTextBuffer
#define OCIJsonClone				  ACIJsonClone
#define OCIJsonBinaryBufferLoad		  ACIJsonBinaryBufferLoad
#define OCIRowidToChar				  ACIRowidToChar

#define OCIServerDetach               ACIServerDetach
#define OCIDescriptorAlloc            ACIDescriptorAlloc
#define OCIArrayDescriptorAlloc       ACIArrayDescriptorAlloc
#define OCIDescriptorFree             ACIDescriptorFree
#define OCIArrayDescriptorFree        ACIArrayDescriptorFree 
#define OCIDescribeAny                ACIDescribeAny
#define OCILogon                      ACILogon
#define OCILogon2                     ACILogon2
#define OCILogoff                     ACILogoff
#define OCIBindByName                 ACIBindByName
#define OCIBindByName2				  ACIBindByName2
#define OCIClientVersion              ACIClientVersion
#define OCIServerVersion              ACIServerVersion
#define OCIServerRelease              ACIServerRelease
#define OCIServerRelease2             ACIServerRelease2
#define OCITransStart                 ACITransStart
#define OCITransDetach                ACITransDetach
#define OCITransForget                ACITransForget
#define OCITransMultiPrepare          ACITransMultiPrepare
#define OCITransPrepare               ACITransPrepare
#define OCIStmtGetBindInfo            ACIStmtGetBindInfo
#define OCIStmtGetPieceInfo			  ACIStmtGetPieceInfo
#define OCIStmtSetPieceInfo			  ACIStmtSetPieceInfo
#define OCIConnectionPoolCreate       ACIConnectionPoolCreate
#define OCIConnectionPoolDestroy      ACIConnectionPoolDestroy
#define OCISessionPoolCreate		  ACISessionPoolCreate
#define OCISessionPoolDestroy		  ACISessionPoolDestroy
#define OCISessionGet                 ACISessionGet
#define OCISessionRelease             ACISessionRelease
#define OCILastInsertId               ACILastInsertId
#define OCIPasswordChange             ACIPasswordChange
#define OCIDBStartup				  ACIDBStartup
#define OCIDBShutdown				  ACIDBShutdown
#define OCIStringAllocSize			  ACIStringAllocSize
#define OCIStringAssign				  ACIStringAssign
#define OCIStringAssignText			  ACIStringAssignText
#define OCIStringPtr				  ACIStringPtr
#define OCIStringResize				  ACIStringResize
#define OCIStringSize				  ACIStringSize	
#define OCIAQDeq					  ACIAQDeq
#define OCIAQDeqArray				  ACIAQDeqArray
#define OCIAQEnq					  ACIAQEnq
#define OCIAQEnqArray				  ACIAQEnqArray
#define OCIAQListen					  ACIAQListen
#define OCIAQListen2				  ACIAQListen2

#define OCITableSize				  ACITableSize
#define OCITableFirst				  ACITableFirst
#define OCITableNext				  ACITableNext
#define OCITableLast				  ACITableLast
#define OCITableDelete				  ACITableDelete
#define OCITableExists				  ACITableExists
#define OCITablePrev				  ACITablePrev
	
#define OCITypeByName				  ACITypeByName
#define OCITypeByRef				  ACITypeByRef
#define OCITypeName					  ACITypeName
#define OCITypeAttrs				  ACITypeAttrs
#define OCITypeMethods				  ACITypeMethods
#define OCITypeCollTypeCode		      ACITypeCollTypeCode
#define OCITypeTypeCode				  ACITypeTypeCode
#define OCITypeIterNew				  ACITypeIterNew
#define OCITypeIterFree				  ACITypeIterFree
#define OCITypeIterSet				  ACITypeIterSet
#define OCITypeAttrNext				  ACITypeAttrNext
#define OCITypeElemName				  ACITypeElemName
#define OCITypeElemTypeCode		      ACITypeElemTypeCode
#define OCITypeElemLength			  ACITypeElemLength
#define OCITypeElemType				  ACITypeElemType
#define OCITypeCollSize				  ACITypeCollSize
#define OCITypeAttrByName			  ACITypeAttrByName
#define OCITypeCollElem			      ACITypeCollElem
#define OCITypeCollExtTypeCode		  ACITypeCollExtTypeCode

#define OCILockOpt					  ACILockOpt
#define OCIObjectMarkStatus			  ACIObjectMarkStatus

#define OCIObjectNew				  ACIObjectNew
#define OCIObjectFree				  ACIObjectFree
#define OCIObjectPin				  ACIObjectPin
#define OCIObjectGetAttr			  ACIObjectGetAttr
#define OCIObjectGetInd				  ACIObjectGetInd
#define OCIObjectGetTypeRef			  ACIObjectGetTypeRef
#define OCIObjectGetProperty		  ACIObjectGetProperty
#define OCIObjectFlush				  ACIObjectFlush
#define OCIObjectGetObjectRef		  ACIObjectGetObjectRef
#define OCIObjectIsLoaded			  ACIObjectIsLoaded
#define OCIObjectMarkUpdate			  ACIObjectMarkUpdate
#define OCIObjectPinCountReset		  ACIObjectPinCountReset
#define OCIObjectPinTable			  ACIObjectPinTable
#define OCIObjectUnmark				  ACIObjectUnmark
#define OCIObjectCopy			      ACIObjectCopy

#define OCIRefToHex					  ACIRefToHex
#define OCIRefFromHex				  ACIRefFromHex
#define OCIRefHexSize				  ACIRefHexSize
#define OCIRefIsNull				  ACIRefIsNull
#define OCIRefIsEqual				  ACIRefIsEqual
#define OCIRefAssign				  ACIRefAssign
#define OCIRefClear					  ACIRefClear

#define OCICollGetElem				  ACICollGetElem
#define OCICollAppend			      ACICollAppend
#define OCICollAssignElem			  ACICollAssignElem
#define OCICollAssign			      ACICollAssign
#define OCICollGetElemArray		      ACICollGetElemArray
#define OCICollIsLocator			  ACICollIsLocator
#define OCICollMax					  ACICollMax
#define OCICollSize					  ACICollSize
#define OCICollTrim					  ACICollTrim

#define OCIIterCreate				  ACIIterCreate
#define OCIIterDelete				  ACIIterDelete
#define OCIIterNext					  ACIIterNext
#define OCIIterPrev					  ACIIterPrev
#define OCIIterGetCurrent			  ACIIterGetCurrent
#define OCIIterInit					  ACIIterInit

#define OCIEnvNlsCreate               ACIEnvNlsCreate
#define OCINlsCharSetIdToName		  ACINlsCharSetIdToName
#define OCINlsCharSetNameToId		  ACINlsCharSetNameToId
#define OCINlsNumericInfoGet		  ACINlsNumericInfoGet
#define OCINlsEnvironmentVariableGet  ACINlsEnvironmentVariableGet
#define OCINlsGetInfo                 ACINlsGetInfo
#define OCINlsCharSetConvert		  ACINlsCharSetConvert  
#define OCINlsNameMap				  ACINlsNameMap
#define OCICharSetToUnicode			  ACICharSetToUnicode
#define OCIUnicodeToCharSet			  ACIUnicodeToCharSet
#define OCICharSetConversionIsReplacementUsed			  ACICharSetConversionIsReplacementUsed

#define OCIPing                       ACIPing
#define OCIBreak					  ACIBreak
#define OCIReset					  ACIReset
#define OCIAdmin					  ACIAdmin

#define	OCISodaBulkInsert				ACISodaBulkInsert
#define	OCISodaBulkInsertAndGet			ACISodaBulkInsertAndGet
#define	OCISodaBulkInsertAndGetWithOpts	ACISodaBulkInsertAndGetWithOpts
#define	OCISodaBulkInsertAndGetWithCont	ACISodaBulkInsertAndGetWithCont
#define	OCISodaBulkInsertWithCtnt		ACISodaBulkInsertWithCtnt
#define	OCISodaCollCreate				ACISodaCollCreate
#define	OCISodaCollCreateWithMetadata	ACISodaCollCreateWithMetadata
#define	OCISodaCollDrop					ACISodaCollDrop
#define	OCISodaCollGetNext				ACISodaCollGetNext
#define	OCISodaCollList					ACISodaCollList
#define	OCISodaCollOpen					ACISodaCollOpen
#define	OCISodaDataGuideGet				ACISodaDataGuideGet
#define	OCISodaDataGuideGetWithOpts		ACISodaDataGuideGetWithOpts
#define	OCISodaAsOfTimestampGet			ACISodaAsOfTimestampGet
#define	OCISodaAsOfScnGet				ACISodaAsOfScnGet
#define	OCISodaDocCount					ACISodaDocCount
#define	OCISodaDocCountWithFilter		ACISodaDocCountWithFilter
#define	OCISodaDocCreate				ACISodaDocCreate
#define	OCISodaDocCreateWithKey			ACISodaDocCreateWithKey
#define	OCISodaDocCreateWithKeyAndMType	ACISodaDocCreateWithKeyAndMType
#define	OCISodaDocGetNext				ACISodaDocGetNext
#define	OCISodaFind						ACISodaFind
#define	OCISodaFindOne					ACISodaFindOne
#define	OCISodaFindOneWithKey			ACISodaFindOneWithKey
#define	OCISodaIndexCreate				ACISodaIndexCreate
#define	OCISodaIndexGet					ACISodaIndexGet
#define	OCISodaIndexList				ACISodaIndexList
#define	OCISodaIndexDrop				ACISodaIndexDrop
#define	OCISodaInsert					ACISodaInsert
#define	OCISodaInsertAndGet				ACISodaInsertAndGet
#define	OCISodaInsertAndGetWithOpts		ACISodaInsertAndGetWithOpts
#define	OCISodaInsertAndGetWithCtnt		ACISodaInsertAndGetWithCtnt
#define	OCISodaInsertWithCtnt			ACISodaInsertWithCtnt
#define	OCISodaRemove					ACISodaRemove
#define	OCISodaRemoveOneWithKey			ACISodaRemoveOneWithKey
#define	OCISodaReplOne					ACISodaReplOne
#define	OCISodaReplOneAndGet			ACISodaReplOneAndGet
#define	OCISodaReplOneAndGetWithCtnt	ACISodaReplOneAndGetWithCtnt
#define	OCISodaReplOneAndGetWithKey		ACISodaReplOneAndGetWithKey
#define	OCISodaReplOneWithCtnt			ACISodaReplOneWithCtnt
#define	OCISodaReplOneWithKey			ACISodaReplOneWithKey
#define	OCISodaSave						ACISodaSave
#define	OCISodaSaveAndGet				ACISodaSaveAndGet
#define	OCISodaSaveAndGetWithOpts		ACISodaSaveAndGetWithOpts
#define	OCISodaSaveWithCtnt				ACISodaSaveWithCtnt
#define	OCISodaSaveAndGetWithCont		ACISodaSaveAndGetWithCont
#define	OCISodaCollTruncate				ACISodaCollTruncate
#define	OCISodaOperKeysSet				ACISodaOperKeysSet

#define OCIDirPathPrepare				ACIDirPathPrepare
#define OCIDirPathColArrayReset			ACIDirPathColArrayReset
#define OCIDirPathStreamReset			ACIDirPathStreamReset
#define OCIDirPathColArrayEntrySet		ACIDirPathColArrayEntrySet
#define OCIDirPathColArrayToStream		ACIDirPathColArrayToStream
#define OCIDirPathLoadStream			ACIDirPathLoadStream
#define OCIDirPathDataSave				ACIDirPathDataSave
#define OCIDirPathFinish				ACIDirPathFinish
#define OCIDirPathAbort					ACIDirPathAbort

#define OCIMemoryAlloc					ACIMemoryAlloc
#define OCIMemoryFree					ACIMemoryFree
#define OCIMemoryResize					ACIMemoryResize

#define OCI_DURATION_PROCESS			ACI_DURATION_PROCESS
#define OCI_DURATION_CALLOUT			ACI_DURATION_CALLOUT
#define OCI_DURATION_STATEMENT			ACI_DURATION_STATEMENT
#define OCI_DURATION_SESSION			ACI_DURATION_SESSION
#define OCI_MEMORY_CLEARED				ACI_MEMORY_CLEARED

//DCIdefine:
#define DCIPrepareForUpdate				ACIPrepareForUpdate
#define DCIBindParamForUpdate			ACIBindParamForUpdate
#define DCIExecuteForUpdate				ACIExecuteForUpdate
//end

//Handle Definitions
#define OCIError                      ACIError
#define OCIEnv                        ACIEnv
#define OCIServer                     ACIServer
#define OCISvcCtx                     ACISvcCtx
#define OCISession                    ACISession
#define OCITrans                      ACITrans
#define OCIStmt                       ACIStmt
#define OCIDefine                     ACIDefine
#define OCIBind                       ACIBind
#define OCIHIMP                       ACIHIMP
#define OCICPool                      ACICPool
#define OCISPool                      ACISPool
#define OCIAuthInfo                   ACIAuthInfo
#define OCIEvent					  ACIEvent
#define OCIColl						  ACIColl
#define OCITable					  ACITable
#define OCIIter						  ACIIter
#define OCIType						  ACIType
#define OCIRef						  ACIRef
#define OCITypeElem					  ACITypeElem
#define OCITypeMethod				  ACITypeMethod
#define OCITypeIter					  ACITypeIter

//DirpathDefinitions for D5000
#define OCIDirPathCtx					ACIDirPathCtx
#define OCIDirPathColArray				ACIDirPathColArray
#define OCIDirPathStream				ACIDirPathStream
//end

// ObejctPropId
#define OCIObjectPropId				  ACIObjectPropId
#define	OCI_OBJECTPROP_LIFETIME		  ACI_OBJECTPROP_LIFETIME
#define OCI_OBJECTPROP_SCHEMA		  ACI_OBJECTPROP_SCHEMA
#define OCI_OBJECTPROP_TABLE		  ACI_OBJECTPROP_TABLE
#define OCI_OBJECTPROP_PIN_DURATION	  ACI_OBJECTPROP_PIN_DURATION
#define OCI_OBJECTPROP_ALLOC_DURATION ACI_OBJECTPROP_ALLOC_DURATION
#define OCI_OBJECTPROP_LOCK		      ACI_OBJECTPROP_LOCK
#define OCI_OBJECTPROP_MARKSTATUS	  ACI_OBJECTPROP_MARKSTATUS
#define OCI_OBJECTPROP_VIEW		      ACI_OBJECTPROP_VIEW

#define OCI_OBJECT_PERSISTENT		  ACI_OBJECT_PERSISTENT
#define OCI_OBJECT_TRANSIENT		  ACI_OBJECT_TRANSIENT
#define OCI_OBJECT_VALUE			  ACI_OBJECT_VALUE

#define OCI_DURATION_TRANS			  ACI_DURATION_TRANS

#define OCITypeCode					  ACITypeCode
#define OCIInd						  ACIInd
#define OCITypeGetOpt				  ACITypeGetOpt
#define OCI_TYPEGET_HEADER			  ACI_TYPEGET_HEADER
#define OCI_TYPEGET_ALL				  ACI_TYPEGET_ALL
#define OCI_IND_NOTNULL				  ACI_IND_NOTNULL
#define OCI_IND_NULL				  ACI_IND_NULL

#define OCI_ATTR_TYPE_NAME			  ACI_ATTR_TYPE_NAME
#define OCI_ATTR_NUM_TYPE_ATTRS		  ACI_ATTR_NUM_TYPE_ATTRS
#define OCI_ATTR_NUM_TYPE_METHODS	  ACI_ATTR_NUM_TYPE_METHODS
#define OCI_ATTR_LIST_TYPE_ATTRS	  ACI_ATTR_LIST_TYPE_ATTRS
#define OCI_ATTR_LIST_TYPE_METHODS	  ACI_ATTR_LIST_TYPE_METHODS
#define OCI_ATTR_MAP_METHOD			  ACI_ATTR_MAP_METHOD
#define OCI_ATTR_ORDER_METHOD		  ACI_ATTR_ORDER_METHOD
#define OCI_ATTR_IS_INVOKER_RIGHTS	  ACI_ATTR_IS_INVOKER_RIGHTS
#define OCI_ATTR_PACKAGE_NAME		  ACI_ATTR_PACKAGE_NAME
#define OCI_ATTR_IS_FINAL_TYPE		  ACI_ATTR_IS_FINAL_TYPE
#define OCI_ATTR_IS_INSTANTIABLE_TYPE	ACI_ATTR_IS_INSTANTIABLE_TYPE
#define OCI_ATTR_IS_SUBTYPE			  ACI_ATTR_IS_SUBTYPE
#define OCI_ATTR_SUPERTYPE_SCHEMA_NAME	ACI_ATTR_SUPERTYPE_SCHEMA_NAME
#define OCI_ATTR_SUPERTYPE_NAME		  ACI_ATTR_SUPERTYPE_NAME
#define OCI_ATTR_TYPECODE			  ACI_ATTR_TYPECODE
#define OCI_ATTR_IS_INCOMPLETE_TYPE	  ACI_ATTR_IS_INCOMPLETE_TYPE
#define OCI_ATTR_IS_SYSTEM_TYPE		  ACI_ATTR_IS_SYSTEM_TYPE
#define OCI_ATTR_IS_PREDEFINED_TYPE	  ACI_ATTR_IS_PREDEFINED_TYPE
#define OCI_ATTR_IS_TRANSIENT_TYPE	  ACI_ATTR_IS_TRANSIENT_TYPE
#define OCI_ATTR_IS_SYSTEM_GENERATED_TYPE	ACI_ATTR_IS_SYSTEM_GENERATED_TYPE
#define OCI_ATTR_HAS_NESTED_TABLE	  ACI_ATTR_HAS_NESTED_TABLE
#define OCI_ATTR_HAS_LOB			  ACI_ATTR_HAS_LOB
#define OCI_ATTR_HAS_FILE			  ACI_ATTR_HAS_FILE
#define OCI_ATTR_COLLATION_ID		  ACI_ATTR_COLLATION_ID
#define OCI_ATTR_COL_PROPERTIES		  ACI_ATTR_COL_PROPERTIES
#define OCI_ATTR_INVISIBLE_COL		  ACI_ATTR_INVISIBLE_COL
#define OCI_ATTR_ROWS_RETURNED		  ACI_ATTR_ROWS_RETURNED
#define OCI_ATTR_OBJECT_NEWNOTNULL	  ACI_ATTR_OBJECT_NEWNOTNULL

#define OCI_IND_NULL				  ACI_IND_NULL
#define OCI_IND_NOTNULL				  ACI_IND_NOTNULL
#define OCI_IND_BADNULL				  ACI_IND_BADNULL
#define OCI_IND_NOTNULLABLE			  ACI_IND_NOTNULLABLE

#define OCI_OBJECT_NEW				  ACI_OBJECT_NEW
#define OCI_OBJECT_DELETED			  ACI_OBJECT_DELETED
#define OCI_OBJECT_UPDATED			  ACI_OBJECT_UPDATED
//is
#define OCI_OBJECT_IS_NEW			  ACI_OBJECT_IS_NEW
#define OCI_OBJECT_IS_UPDATED		  ACI_OBJECT_IS_UPDATED
#define OCI_OBJECT_IS_DELETED	      ACI_OBJECT_IS_DELETED
#define OCI_OBJECT_IS_DIRTY			  ACI_OBJECT_IS_DIRTY

#define OCI_DURATION_DEFAULT		  ACI_DURATION_DEFAULT
#define OCI_OBJECTFREE_FORCE		  ACI_OBJECTFREE_FORCE

#define OCI_TYPECODE_OBJECT			  ACI_TYPECODE_OBJECT
#define OCI_TYPECODE_REF			  ACI_TYPECODE_REF
#define OCI_TYPECODE_NAMEDCOLLECTION  ACI_TYPECODE_NAMEDCOLLECTION
#define OCI_TYPECODE_SIGNED8		  ACI_TYPECODE_SIGNED8
#define OCI_TYPECODE_UNSIGNED8		  ACI_TYPECODE_UNSIGNED8
#define OCI_TYPECODE_OCTET			  ACI_TYPECODE_OCTET
#define OCI_TYPECODE_UNSIGNED16		  ACI_TYPECODE_UNSIGNED16
#define OCI_TYPECODE_UNSIGNED32		  ACI_TYPECODE_UNSIGNED32
#define OCI_TYPECODE_REAL			  ACI_TYPECODE_REAL
#define OCI_TYPECODE_DOUBLE			  ACI_TYPECODE_DOUBLE
#define OCI_TYPECODE_INTEGER		  ACI_TYPECODE_INTEGER
#define OCI_TYPECODE_SIGNED16		  ACI_TYPECODE_SIGNED16
#define OCI_TYPECODE_SIGNED32	      ACI_TYPECODE_SIGNED32
#define OCI_TYPECODE_DECIMAL		  ACI_TYPECODE_DECIMAL
#define OCI_TYPECODE_FLOAT		      ACI_TYPECODE_FLOAT
#define OCI_TYPECODE_SMALLINT		  ACI_TYPECODE_SMALLINT
#define OCI_TYPECODE_NUMBER			  ACI_TYPECODE_NUMBER
#define OCI_TYPECODE_DATE			  ACI_TYPECODE_DATE
#define OCI_TYPECODE_VARCHAR2		  ACI_TYPECODE_VARCHAR2
#define OCI_TYPECODE_VARCHAR	      ACI_TYPECODE_VARCHAR
#define OCI_TYPECODE_CHAR		      ACI_TYPECODE_CHAR
#define OCI_TYPECODE_TIME			  ACI_TYPECODE_TIME
#define OCI_TYPECODE_TIME_TZ		  ACI_TYPECODE_TIME_TZ
#define OCI_TYPECODE_TIMESTAMP		  ACI_TYPECODE_TIMESTAMP
#define OCI_TYPECODE_TIMESTAMP_TZ	  ACI_TYPECODE_TIMESTAMP_TZ
#define OCI_TYPECODE_TIMESTAMP_LTZ    ACI_TYPECODE_TIMESTAMP_LTZ
#define OCI_TYPECODE_CLOB			  ACI_TYPECODE_CLOB
#define OCI_TYPECODE_BLOB			  ACI_TYPECODE_BLOB
#define OCI_TYPECODE_BFILE			  ACI_TYPECODE_BFILE
#define OCI_TYPECODE_BOOLEAN		  ACI_TYPECODE_BOOLEAN
#define OCI_TYPECODE_TABLE			  ACI_TYPECODE_TABLE
#define OCI_TYPECODE_ITABLE			  ACI_TYPECODE_ITABLE
#define OCI_TYPECODE_VARRAY			  ACI_TYPECODE_VARRAY
#define OCI_TYPECODE_UROWID			  ACI_TYPECODE_UROWID
#define OCI_TYPECODE_RAW			  ACI_TYPECODE_RAW

#define OCI_TYPECODE_NONE			  ACI_TYPECODE_NONE


#define OCI_ATTR_REF_TDO			  ACI_ATTR_REF_TDO
#define OCI_ATTR_LTYPE				  ACI_ATTR_LTYPE
#define OCI_ATTR_NUM_ELEMS		      ACI_ATTR_NUM_ELEMS

#define OCI_PIN_ANY					  ACI_PIN_ANY
#define OCI_PIN_DEFAULT				  ACI_PIN_DEFAULT
#define OCI_PIN_RECENT				  ACI_PIN_RECENT
#define OCI_PIN_LATEST				  ACI_PIN_LATEST

#define OCI_LOCK_NONE				  ACI_LOCK_NONE
#define OCI_LOCK_X					  ACI_LOCK_X
#define OCI_LOCK_X_NOWAIT			  ACI_LOCK_X_NOWAIT

#define	OCI_LTYPE_UNK				  ACI_LTYPE_UNK
#define	OCI_LTYPE_COLUMN			  ACI_LTYPE_COLUMN
#define	OCI_LTYPE_ARG_PROC			  ACI_LTYPE_ARG_PROC
#define	OCI_LTYPE_ARG_FUNC			  ACI_LTYPE_ARG_FUNC
#define	OCI_LTYPE_SUBPRG		      ACI_LTYPE_SUBPRG
#define	OCI_LTYPE_TYPE_ATTR			  ACI_LTYPE_TYPE_ATTR
#define	OCI_LTYPE_TYPE_METHOD		  ACI_LTYPE_TYPE_METHOD
#define	OCI_LTYPE_TYPE_ARG_PROC		  ACI_LTYPE_TYPE_ARG_PROC
#define	OCI_LTYPE_TYPE_ARG_FUNC		  ACI_LTYPE_TYPE_ARG_FUNC
#define	OCI_LTYPE_SCH_OBJ			  ACI_LTYPE_SCH_OBJ
#define	OCI_LTYPE_DB_SCH			  ACI_LTYPE_DB_SCH
#define	OCI_LTYPE_TYPE_SUBTYPE		  ACI_LTYPE_TYPE_SUBTYPE
#define	OCI_LTYPE_TABLE_ALIAS		  ACI_LTYPE_TABLE_ALIAS
#define	OCI_LTYPE_VARIABLE_TYPE		  ACI_LTYPE_VARIABLE_TYPE
#define OCI_LTYPE_NAME_VALUE		  ACI_LTYPE_NAME_VALUE


#define OCIComplexObject			  ACIComplexObject

#define OCINumber                     ACINumber
#define OCI_NUMBER_SIGNED             ACI_NUMBER_SIGNED
#define OCI_NUMBER_UNSIGNED           ACI_NUMBER_UNSIGNED
#define OCINumberPart                 ACINumberPart

#define OCINumberAdd                  ACINumberAdd
#define OCINumberSub                  ACINumberSub
#define OCINumberMul                  ACINumberMul
#define OCINumberDiv                  ACINumberDiv
#define OCINumberFromInt              ACINumberFromInt
#define OCINumberToInt                ACINumberToInt
#define OCINumberMod                  ACINumberMod
#define OCINumberAbs                  ACINumberAbs
#define OCINumberSign                 ACINumberSign
#define OCINumberFromText             ACINumberFromText
#define OCINumberSetZero              ACINumberSetZero
#define OCINumberCmp                  ACINumberCmp
#define OCINumberCeil                 ACINumberCeil
#define OCINumberFloor                ACINumberFloor
#define OCINumberDec                  ACINumberDec
#define OCINumberInc                  ACINumberInc
#define OCINumberTrunc                ACINumberTrunc
#define OCINumberLn                   ACINumberLn
#define OCINumberLog                  ACINumberLog
#define OCINumberPower                ACINumberPower
#define OCINumberExp                  ACINumberExp
#define OCINumberSqrt                 ACINumberSqrt
#define OCINumberAssign               ACINumberAssign
#define OCINumberIsZero               ACINumberIsZero
#define OCINumberNeg                  ACINumberNeg
#define OCINumberFromReal             ACINumberFromReal
#define OCINumberToReal               ACINumberToReal
#define OCINumberToText               ACINumberToText
#define OCINumberIsInt                ACINumberIsInt
#define OCINumberSetPi                ACINumberSetPi
#define OCINumberShift                ACINumberShift
#define OCINumberIntPower             ACINumberIntPower
#define OCINumberRound                ACINumberRound
#define OCINumberSin                  ACINumberSin				
#define OCINumberCos                  ACINumberCos
#define OCINumberTan                  ACINumberTan
#define OCINumberArcSin               ACINumberArcSin
#define OCINumberArcCos               ACINumberArcCos
#define OCINumberArcTan               ACINumberArcTan
#define OCINumberArcTan2              ACINumberArcTan2
#define OCINumberHypSin               ACINumberHypSin
#define OCINumberHypCos               ACINumberHypCos
#define OCINumberHypTan               ACINumberHypTan
#define OCINumberToRealArray          ACINumberToRealArray

#define OCIRaw						  ACIRaw							
#define OCIRawSize					  ACIRawSize
#define OCIRawPtr					  ACIRawPtr
#define OCIRawResize				  ACIRawResize
#define OCIRawAssignBytes			  ACIRawAssignBytes
#define OCIRawAllocSize				  ACIRawAllocSize
#define OCIRawAssignRaw				  ACIRawAssignRaw

#define OCIThreadClose				  ACIThreadClose
#define OCIThreadCreate				  ACIThreadCreate
#define OCIThreadHandleGet			  ACIThreadHandleGet
#define OCIThreadHndDestroy			  ACIThreadHndDestroy
#define OCIThreadHndInit			  ACIThreadHndInit
#define OCIThreadIdDestroy			  ACIThreadIdDestroy
#define OCIThreadIdGet				  ACIThreadIdGet
#define OCIThreadIdInit				  ACIThreadIdInit
#define OCIThreadIdNull				  ACIThreadIdNull
#define OCIThreadIdSame				  ACIThreadIdSame
#define OCIThreadIdSet				  ACIThreadIdSet
#define OCIThreadIdSetNull			  ACIThreadIdSetNull
#define OCIThreadInit				  ACIThreadInit
#define OCIThreadIsMulti			  ACIThreadIsMulti
#define OCIThreadJoin				  ACIThreadJoin
#define OCIThreadKeyDestroy			  ACIThreadKeyDestroy
#define OCIThreadKeyGet				  ACIThreadKeyGet
#define OCIThreadKeyInit			  ACIThreadKeyInit
#define OCIThreadKeySet				  ACIThreadKeySet
#define OCIThreadMutexAcquire		  ACIThreadMutexAcquire
#define OCIThreadMutexDestroy		  ACIThreadMutexDestroy
#define OCIThreadMutexInit			  ACIThreadMutexInit
#define OCIThreadMutexRelease		  ACIThreadMutexRelease
#define OCIThreadProcessInit		  ACIThreadProcessInit
#define OCIThreadTerm				  ACIThreadTerm

#define OCI_ENV_NO_MUTEX			  ACI_ENV_NO_MUTEX
//Error Return Values
#define OCI_SUCCESS                   ACI_SUCCESS
#define OCI_SUCCESS_WITH_INFO         ACI_SUCCESS_WITH_INFO
#define OCI_NEED_DATA                 ACI_NEED_DATA
#define OCI_NO_DATA                   ACI_NO_DATA
#define OCI_ERROR                     ACI_ERROR
#define OCI_INVALID_HANDLE            ACI_INVALID_HANDLE
#define OCI_STILL_EXECUTING           ACI_STILL_EXECUTING
#define OCI_CONTINUE                  ACI_CONTINUE
#define OCI_SERVER_NOT_CONNECTED	  ACI_SERVER_NOT_CONNECTED
#define OCI_SERVER_NORMAL 			  ACI_SERVER_NORMAL 

//Error
#define OCI_ERROR_MAXMSG_SIZE		ACI_ERROR_MAXMSG_SIZE
#define OCI_ERROR_MAXMSG_SIZE2      ACI_ERROR_MAXMSG_SIZE2

//Handle Types
#define OCI_HTYPE_ERROR               ACI_HTYPE_ERROR
#define OCI_HTYPE_SERVER              ACI_HTYPE_SERVER
#define OCI_HTYPE_SVCCTX              ACI_HTYPE_SVCCTX
#define OCI_HTYPE_SESSION             ACI_HTYPE_SESSION
#define OCI_HTYPE_TRANS               ACI_HTYPE_TRANS
#define OCI_HTYPE_STMT                ACI_HTYPE_STMT
#define OCI_HTYPE_ENV                 ACI_HTYPE_ENV
#define OCI_HTYPE_DESCRIBE            ACI_HTYPE_DESCRIBE 
#define OCI_HTYPE_CPOOL               ACI_HTYPE_CPOOL
#define OCI_HTYPE_AUTHINFO            ACI_HTYPE_AUTHINFO
#define OCI_HTYPE_BIND				  ACI_HTYPE_BIND
#define OCI_HTYPE_DEFINE			  ACI_HTYPE_DEFINE

#define OCI_HTYPE_FIRST  					ACI_HTYPE_FIRST
#define OCI_HTYPE_COMPLEXOBJECT	            ACI_HTYPE_COMPLEXOBJECT
#define OCI_HTYPE_SECURITY     	            ACI_HTYPE_SECURITY
#define OCI_HTYPE_SUBSCRIPTION 	            ACI_HTYPE_SUBSCRIPTION
#define OCI_HTYPE_DIRPATH_CTX				ACI_HTYPE_DIRPATH_CTX
#define OCI_HTYPE_DIRPATH_COLUMN_ARRAY 	    ACI_HTYPE_DIRPATH_COLUMN_ARRAY
#define OCI_HTYPE_DIRPATH_STREAM       	    ACI_HTYPE_DIRPATH_STREAM
#define OCI_HTYPE_PROC                 	    ACI_HTYPE_PROC
#define OCI_HTYPE_DIRPATH_FN_CTX       	    ACI_HTYPE_DIRPATH_FN_CTX
#define OCI_HTYPE_DIRPATH_FN_COL_ARRAY 	    ACI_HTYPE_DIRPATH_FN_COL_ARRAY
#define OCI_HTYPE_XADSESSION    	        ACI_HTYPE_XADSESSION
#define OCI_HTYPE_XADTABLE      	        ACI_HTYPE_XADTABLE
#define OCI_HTYPE_XADFIELD      	        ACI_HTYPE_XADFIELD
#define OCI_HTYPE_XADGRANULE    	        ACI_HTYPE_XADGRANULE
#define OCI_HTYPE_XADRECORD     	        ACI_HTYPE_XADRECORD
#define OCI_HTYPE_XADIO  	                ACI_HTYPE_XADIO
#define OCI_HTYPE_SPOOL        	            ACI_HTYPE_SPOOL
#define OCI_HTYPE_ADMIN 	                ACI_HTYPE_ADMIN
#define OCI_HTYPE_EVENT 	                ACI_HTYPE_EVENT
#define OCI_HTYPE_LAST  	                ACI_HTYPE_LAST

//Various Modes
#define OCI_DEFAULT                   ACI_DEFAULT
#define OCI_CPOOL                     ACI_CPOOL

//ACIInitialize Modes / ACICreateEnvironment Modes
#define OCI_THREADED                  ACI_THREADED
#define OCI_OBJECT                    ACI_OBJECT
#define OCI_EVENTS					  ACI_EVENTS

//Execution Modes
#define OCI_BATCH_MODE				  ACI_BATCH_MODE
#define OCI_EXACT_FETCH               ACI_EXACT_FETCH
#define OCI_DESCRIBE_ONLY             ACI_DESCRIBE_ONLY
#define OCI_COMMIT_ON_SUCCESS         ACI_COMMIT_ON_SUCCESS
#define OCI_BATCH_ERRORS              ACI_BATCH_ERRORS
#define OCI_STMT_SCROLLABLE_READONLY  ACI_STMT_SCROLLABLE_READONLY
#define OCI_RETURN_ROW_COUNT_ARRAY    ACI_RETURN_ROW_COUNT_ARRAY
#define OCI_ATTR_PREFETCH_MEMORY	  ACI_ATTR_PREFETCH_MEMORY

// OCIInputValidate Modes
#define OCI_INPUTVLD_CONNSTR_ATTR  ACI_INPUTVLD_CONNSTR_ATTR

/*-------------------------Credential Types----------------------------------*/
#define OCI_CRED_RDBMS      ACI_CRED_RDBMS
#define OCI_CRED_EXT        ACI_CRED_EXT
#define OCI_CRED_PROXY      ACI_CRED_PROXY
#define OCI_CRED_RESERVED_1 ACI_CRED_RESERVED_1
#define OCI_CRED_RESERVED_2 ACI_CRED_RESERVED_2
/*---------------------------------------------------------------------------*/

//Attribute Types
#define OCI_ATTR_SERVER               ACI_ATTR_SERVER
#define OCI_ATTR_USERNAME             ACI_ATTR_USERNAME
#define OCI_ATTR_PASSWORD             ACI_ATTR_PASSWORD
#define OCI_ATTR_STMT_TYPE            ACI_ATTR_STMT_TYPE
#define OCI_ATTR_ENV                  ACI_ATTR_ENV
#define OCI_CRED_RDBMS                ACI_CRED_RDBMS
#define OCI_ATTR_SESSION              ACI_ATTR_SESSION
#define OCI_ATTR_TRANS                ACI_ATTR_TRANS
#define OCI_ATTR_DATA_TYPE            ACI_ATTR_DATA_TYPE
#define OCI_ATTR_PARAM_COUNT          ACI_ATTR_PARAM_COUNT
#define OCI_ATTR_ROW_COUNT            ACI_ATTR_ROW_COUNT
#define OCI_ATTR_PARAM                ACI_ATTR_PARAM
#define OCI_ATTR_LIST_COLUMNS         ACI_ATTR_LIST_COLUMNS
#define OCI_ATTR_NUM_COLS             ACI_ATTR_NUM_COLS
#define OCI_ATTR_PRECISION            ACI_ATTR_PRECISION
#define OCI_ATTR_SCALE                ACI_ATTR_SCALE
#define OCI_ATTR_DATA_SIZE            ACI_ATTR_DATA_SIZE
#define OCI_ATTR_PREFETCH_ROWS        ACI_ATTR_PREFETCH_ROWS
#define OCI_ATTR_DML_ROW_OFFSET		  ACI_ATTR_DML_ROW_OFFSET
#define OCI_ATTR_NUM_DML_ERRORS		  ACI_ATTR_NUM_DML_ERRORS
#define OCI_ATTR_NAME                 ACI_ATTR_NAME
#define OCI_ATTR_ROWS_FETCHED         ACI_ATTR_ROWS_FETCHED
#define OCI_ATTR_NOCACHE			  ACI_ATTR_NOCACHE
#define OCI_ATTR_BIND_COUNT           ACI_ATTR_BIND_COUNT
#define OCI_ATTR_ROWID                ACI_ATTR_ROWID 
#define OCI_ATTR_IS_NULL              ACI_ATTR_IS_NULL
#define OCI_ATTR_CONNECTION_CLASS     ACI_ATTR_CONNECTION_CLASS
#define OCI_ATTR_MODULE               ACI_ATTR_MODULE
#define OCI_ATTR_CURRENT_SCHEMA       ACI_ATTR_CURRENT_SCHEMA
#define OCI_ATTR_PURITY               ACI_ATTR_PURITY
#define OCI_ATTR_PURITY_NEW           ACI_ATTR_PURITY_NEW
#define OCI_ATTR_PURITY_DEFAULT       ACI_ATTR_PURITY_DEFAULT  
#define OCI_ATTR_SCHEMA_NAME		  ACI_ATTR_SCHEMA_NAME
#define OCI_ATTR_DATEFORMAT			  ACI_ATTR_DATEFORMAT
#define OCI_ATTR_NUM_COLS			  ACI_ATTR_NUM_COLS
#define OCI_ATTR_LIST_COLUMNS		  ACI_ATTR_LIST_COLUMNS
#define OCI_ATTR_BUF_SIZE			  ACI_ATTR_BUF_SIZE
#define OCI_ATTR_CURRENT_POSITION	  ACI_ATTR_CURRENT_POSITION
#define OCI_ATTR_EVTCBK				  ACI_ATTR_EVTCBK
#define OCI_ATTR_EVTCTX               ACI_ATTR_EVTCTX
#define OCI_ATTR_DBNAME			      ACI_ATTR_DBNAME
#define OCI_ATTR_HOSTNAME			  ACI_ATTR_HOSTNAME
#define OCI_ATTR_HA_SRVFIRST          ACI_ATTR_HA_SRVFIRST
#define OCI_ATTR_HA_SRVNEXT			  ACI_ATTR_HA_SRVNEXT
#define OCI_ATTR_USER_MEMORY		  ACI_ATTR_USER_MEMORY
#define OCI_ATTR_SUB_NAME             ACI_ATTR_SUB_NAME
#define OCI_ATTR_DIRPATH_PARALLEL     ACI_ATTR_DIRPATH_PARALLEL
#define OCI_ATTR_DIRPATH_NOLOG        ACI_ATTR_DIRPATH_NOLOG
#define OCI_ATTR_NUM_ROWS             ACI_ATTR_NUM_ROWS
#define OCI_ATTR_COL_COUNT            ACI_ATTR_COL_COUNT
#define OCI_ATTR_DIRPATH_INPUT        ACI_ATTR_DIRPATH_INPUT
#define OCI_ATTR_STMTCACHESIZE        ACI_ATTR_STMTCACHESIZE
#define OCI_ATTR_SESSGET_FLAGS		  ACI_ATTR_SESSGET_FLAGS
#define OCI_ATTR_CALL_TIMEOUT         ACI_ATTR_CALL_TIMEOUT
#define OCI_ATTR_STMT_IS_RETURNING	  ACI_ATTR_STMT_IS_RETURNING
#define OCI_ATTR_STATEMENT			  ACI_ATTR_STATEMENT
#define OCI_ATTR_LOBEMPTY			  ACI_ATTR_LOBEMPTY
#define OCI_ATTR_MAXDATA_SIZE		  ACI_ATTR_MAXDATA_SIZE
#define OCI_ATTR_MAXCHAR_SIZE		  ACI_ATTR_MAXCHAR_SIZE
#define OCI_ATTR_DEFAULT_LOBPREFETCH_SIZE  ACI_ATTR_DEFAULT_LOBPREFETCH_SIZE
#define OCI_ATTR_LOBPREFETCH_SIZE     ACI_ATTR_LOBPREFETCH_SIZE
#define OCI_ATTR_LOBPREFETCH_LENGTH   ACI_ATTR_LOBPREFETCH_LENGTH
#define OCI_ATTR_PARSE_ERROR_OFFSET   ACI_ATTR_PARSE_ERROR_OFFSET
#define OCI_DIRPATH_INPUT_TEXT		  ACI_DIRPATH_INPUT_TEXT
#define OCI_ATTR_SERVER_STATUS		  ACI_ATTR_SERVER_STATUS
#define OCI_ATTR_EXTERNAL_NAME		  ACI_ATTR_EXTERNAL_NAME
#define OCI_ATTR_INTERNAL_NAME		  ACI_ATTR_INTERNAL_NAME
#define OCI_ATTR_INSTNAME			  ACI_ATTR_INSTNAME
#define OCI_ATTR_OBJECT				  ACI_ATTR_OBJECT
#define OCI_ATTR_ENV_UTF16			  ACI_ATTR_ENV_UTF16
#define OCI_ATTR_ENV_NCHARSET_ID	  ACI_ATTR_ENV_NCHARSET_ID
#define OCI_ATTR_ENV_NLS_LANGUAGE	  ACI_ATTR_ENV_NLS_LANGUAGE
#define OCI_ATTR_ENV_NLS_TERRITORY	  ACI_ATTR_ENV_NLS_TERRITORY
#define OCI_ATTR_BREAK_ON_NET_TIMEOUT	ACI_ATTR_BREAK_ON_NET_TIMEOUT
#define OCI_ATTR_NONBLOCKING_MODE		ACI_ATTR_NONBLOCKING_MODE
#define OCI_ATTR_SEND_TIMEOUT		   ACI_ATTR_SEND_TIMEOUT
#define OCI_ATTR_RECEIVE_TIMEOUT	   ACI_ATTR_RECEIVE_TIMEOUT
#define OCI_ATTR_IN_V8_MODE			   ACI_ATTR_IN_V8_MODE
#define OCI_ATTR_SERVER_GROUP		   ACI_ATTR_SERVER_GROUP
#define OCI_ATTR_SQL_ID				   ACI_ATTR_SQL_ID
#define OCI_ATTR_STMT_STATE			   ACI_ATTR_STMT_STATE
#define OCI_ATTR_FETCH_ROWID		   ACI_ATTR_FETCH_ROWID
#define OCI_ATTR_COLLECTION_TYPECODE  ACI_ATTR_COLLECTION_TYPECODE
#define OCI_ATTR_COLLECTION_ELEMENT	  ACI_ATTR_COLLECTION_ELEMENT
#define OCI_ATTR_REF_TDO			  ACI_ATTR_REF_TDO

/* --------------------------- Connection Pool Attributes ------------------ */
#define OCI_ATTR_CONN_NOWAIT          ACI_ATTR_CONN_NOWAIT
#define OCI_ATTR_CONN_BUSY_COUNT      ACI_ATTR_CONN_BUSY_COUNT            
#define OCI_ATTR_CONN_OPEN_COUNT      ACI_ATTR_CONN_OPEN_COUNT      
#define OCI_ATTR_CONN_TIMEOUT         ACI_ATTR_CONN_TIMEOUT           
#define OCI_ATTR_CONN_MIN             ACI_ATTR_CONN_MIN      
#define OCI_ATTR_CONN_MAX             ACI_ATTR_CONN_MAX      
#define OCI_ATTR_CONN_INCR            ACI_ATTR_CONN_INCR      

/* --------------------------- Session Pool Attributes ------------------ */
#define OCI_ATTR_SPOOL_AUTH						ACI_ATTR_SPOOL_AUTH
#define OCI_ATTR_FOCBK							ACI_ATTR_FOCBK
#define OCI_ATTR_SPOOL_TIMEOUT					ACI_ATTR_SPOOL_TIMEOUT
#define OCI_ATTR_SPOOL_GETMODE					ACI_ATTR_SPOOL_GETMODE
#define OCI_ATTR_SPOOL_BUSY_COUNT				ACI_ATTR_SPOOL_BUSY_COUNT
#define OCI_ATTR_SPOOL_OPEN_COUNT				ACI_ATTR_SPOOL_OPEN_COUNT
#define OCI_ATTR_SPOOL_MIN						ACI_ATTR_SPOOL_MIN
#define OCI_ATTR_SPOOL_MAX						ACI_ATTR_SPOOL_MAX
#define OCI_ATTR_SPOOL_INCR						ACI_ATTR_SPOOL_INCR
#define OCI_ATTR_SPOOL_MAX_LIFETIME_SESSION		ACI_ATTR_SPOOL_MAX_LIFETIME_SESSION
#define OCI_ATTR_SPOOL_MAX_USE_SESSION			ACI_ATTR_SPOOL_MAX_USE_SESSION
#define OCI_ATTR_SPOOL_STMTCACHESIZE			ACI_ATTR_SPOOL_STMTCACHESIZE
#define OCI_ATTR_SPOOL_WAIT_TIMEOUT				ACI_ATTR_SPOOL_WAIT_TIMEOUT
#define OCI_ATTR_SPOOL_MAX_PER_SHARD			ACI_ATTR_SPOOL_MAX_PER_SHARD
#define OCI_ATTR_SPOOL_DRAIN_TIMEOUT			ACI_ATTR_SPOOL_DRAIN_TIMEOUT

#define OCI_SPOOL_ATTRVAL_WAIT					ACI_SPOOL_ATTRVAL_WAIT 
#define OCI_SPOOL_ATTRVAL_NOWAIT				ACI_SPOOL_ATTRVAL_NOWAIT 
#define OCI_SPOOL_ATTRVAL_FORCEGET				ACI_SPOOL_ATTRVAL_FORCEGET 
#define OCI_SPOOL_ATTRVAL_TIMEDWAIT				ACI_SPOOL_ATTRVAL_TIMEDWAIT

//modeֵ
#define OCI_SPD_FORCE							ACI_SPD_FORCE
#define OCI_SPD_DRAIN							ACI_SPD_DRAIN
#define OCI_SPC_REINITIALIZE					ACI_SPC_REINITIALIZE
#define OCI_SPC_STMTCACHE						ACI_SPC_STMTCACHE
#define OCI_SPC_HOMOGENEOUS						ACI_SPC_HOMOGENEOUS
#define OCI_SPC_NO_RLB							ACI_SPC_NO_RLB 

//defines
#define OCI_ATTR_MAXLEN_COMPAT_STANDARD		    ACI_ATTR_MAXLEN_COMPAT_STANDARD
#define OCI_ATTR_MAXLEN_COMPAT_EXTENDED		    ACI_ATTR_MAXLEN_COMPAT_EXTENDED
#define OCI_ATTR_VARTYPE_MAXLEN_COMPAT			ACI_ATTR_VARTYPE_MAXLEN_COMPAT

#define OCI_SESSGET_FLAGS_NEW					ACI_SESSGET_FLAGS_NEW
#define OCI_SESSGET_FLAGS_POOLED_SERVER			ACI_SESSGET_FLAGS_POOLED_SERVER
#define OCI_SESSGET_FLAGS_SHARD					ACI_SESSGET_FLAGS_SHARD
#define OCI_SESSGET_FLAGS_RAC_DATA_AFFN			ACI_SESSGET_FLAGS_RAC_DATA_AFFN

#define OCI_ATTR_MAX_CHARSET_RATIO              ACI_ATTR_MAX_CHARSET_RATIO
#define OCI_ATTR_MAX_NCHARSET_RATIO             ACI_ATTR_MAX_NCHARSET_RATIO
#define OCI_ATTR_STMTCACHE_CBKCTX			    ACI_ATTR_STMTCACHE_CBKCTX
#define OCI_ATTR_STMTCACHE_CBK					ACI_ATTR_STMTCACHE_CBK
#define OCI_CBK_STMTCACHE_STMTPURGE				ACI_CBK_STMTCACHE_STMTPURGE
#define OCI_ATTR_DML_ROW_COUNT_ARRAY			ACI_ATTR_DML_ROW_COUNT_ARRAY

#define OCI_PREP2_GET_SQL_ID				    ACI_PREP2_GET_SQL_ID
#define OCI_STMT_STATE_INITIALIZED				ACI_STMT_STATE_INITIALIZED
#define OCI_STMT_STATE_EXECUTED					ACI_STMT_STATE_EXECUTED
#define OCI_STMT_STATE_END_OF_FETCH				ACI_STMT_STATE_END_OF_FETCH
#define OCI_BIND_SOFT							ACI_BIND_SOFT
#define OCI_DEFINE_SOFT							ACI_DEFINE_SOFT
#define OCI_ATTR_UB8_ROW_COUNT					ACI_ATTR_UB8_ROW_COUNT
#define OCI_ATTR_IMPLICIT_RESULT_COUNT			ACI_ATTR_IMPLICIT_RESULT_COUNT
#define OCI_ATTR_DRIVER_NAME				    ACI_ATTR_DRIVER_NAME
#define OCI_ATTR_EDITION						ACI_ATTR_EDITION

/*--------------------------- soda ---------------------------------------*/
#define OCI_ATTR_SODA_DOC_COUNT					ACI_ATTR_SODA_DOC_COUNT
#define OCI_SODA_ATOMIC_COMMIT					ACI_SODA_ATOMIC_COMMIT
#define OCI_SODA_COLL_CREATE_MAP				ACI_SODA_COLL_CREATE_MAP
#define OCI_SODA_INDEX_DROP_FORCE				ACI_SODA_INDEX_DROP_FORCE
#define OCI_SODA_DETECT_JSON_ENC				ACI_SODA_DETECT_JSON_ENC
#define OCI_SODA_AS_STORED						ACI_SODA_AS_STORED
#define OCI_SODA_AS_AL32UTF8					ACI_SODA_AS_AL32UTF8
#define OCI_SODA_KEY_METHOD_UUID				ACI_SODA_KEY_METHOD_UUID
#define OCI_SODA_KEY_METHOD_GUID				ACI_SODA_KEY_METHOD_GUID
#define OCI_SODA_KEY_METHOD_SEQUENCE			ACI_SODA_KEY_METHOD_SEQUENCE
#define OCI_SODA_KEY_METHOD_CLIENT				ACI_SODA_KEY_METHOD_CLIENT
#define OCI_SODA_JSON_VALIDATION_STRICT			ACI_SODA_JSON_VALIDATION_STRICT
#define OCI_SODA_JSON_VALIDATION_LAX   			ACI_SODA_JSON_VALIDATION_LAX   
#define OCI_SODA_JSON_VALIDATION_STD   			ACI_SODA_JSON_VALIDATION_STD   
#define OCI_SODA_LOB_COMPRESS_NONE  			ACI_SODA_LOB_COMPRESS_NONE  
#define OCI_SODA_LOB_COMPRESS_HIGH  			ACI_SODA_LOB_COMPRESS_HIGH  
#define OCI_SODA_LOB_COMPRESS_MEDIUM			ACI_SODA_LOB_COMPRESS_MEDIUM
#define OCI_SODA_LOB_COMPRESS_LOW   			ACI_SODA_LOB_COMPRESS_LOW   
#define OCI_SODA_LOB_ENCRYPT_NONE    			ACI_SODA_LOB_ENCRYPT_NONE    
#define OCI_SODA_LOB_ENCRYPT_3DES168 			ACI_SODA_LOB_ENCRYPT_3DES168 
#define OCI_SODA_LOB_ENCRYPT_AES128  			ACI_SODA_LOB_ENCRYPT_AES128  
#define OCI_SODA_LOB_ENCRYPT_AES192  			ACI_SODA_LOB_ENCRYPT_AES192  
#define OCI_SODA_LOB_ENCRYPT_AES256  			ACI_SODA_LOB_ENCRYPT_AES256  
#define OCI_SODA_VERSION_UUID      				ACI_SODA_VERSION_UUID      
#define OCI_SODA_VERSION_TIMESTAMP 				ACI_SODA_VERSION_TIMESTAMP 
#define OCI_SODA_VERSION_MD5       				ACI_SODA_VERSION_MD5       
#define OCI_SODA_VERSION_SHA256    				ACI_SODA_VERSION_SHA256    
#define OCI_SODA_VERSION_SEQUENTIAL				ACI_SODA_VERSION_SEQUENTIAL
#define OCI_SODA_VERSION_NONE      				ACI_SODA_VERSION_NONE
/*---------------------------------- 21C 支持，先把映射写上 -------------------------------------------------*/
#define OCI_SODA_COLL_DROP_PURGE 				ACI_SODA_COLL_DROP_PURGE
#define OCI_SODA_COLL_DROP_MAPPED_TABLE			ACI_SODA_COLL_DROP_MAPPED_TABLE
#define OCI_SODA_DG_FMT_HIERARCHICAL			ACI_SODA_DG_FMT_HIERARCHICAL
#define OCI_ATTR_SODA_SAMPLE_PCT				ACI_ATTR_SODA_SAMPLE_PCT
#define OCI_ATTR_SODA_SAMPLE_SEED				ACI_ATTR_SODA_SAMPLE_SEED
#define OCI_ATTR_SODA_SAMPLE_METHOD				ACI_ATTR_SODA_SAMPLE_METHOD
#define OCI_ATTR_SODA_FETCH_ARRAY_SIZE			ACI_ATTR_SODA_FETCH_ARRAY_SIZE
#define OCI_ATTR_SODA_AS_OF_SCN					ACI_ATTR_SODA_AS_OF_SCN
#define OCI_ATTR_SODA_AS_OF_TSTAMP				ACI_ATTR_SODA_AS_OF_TSTAMP
#define OCI_ATTR_SODA_LOCK						ACI_ATTR_SODA_LOCK
#define OCI_ATTR_SODA_HINT						ACI_ATTR_SODA_HINT
#define OCI_ATTR_SODA_METADATA_CACHE			ACI_ATTR_SODA_METADATA_CACHE
/*---------------------------------- 21C 支持，先把映射写上 -------------------------------------------------*/

#define OCI_ATTR_SODA_COLL_NAME					ACI_ATTR_SODA_COLL_NAME         
#define OCI_ATTR_SODA_DESCRIPTOR               	ACI_ATTR_SODA_DESCRIPTOR        
#define OCI_ATTR_SODA_SCHEMA                   	ACI_ATTR_SODA_SCHEMA            
#define OCI_ATTR_SODA_TABLE_NAME               	ACI_ATTR_SODA_TABLE_NAME        
#define OCI_ATTR_SODA_VIEW_NAME                	ACI_ATTR_SODA_VIEW_NAME         
#define OCI_ATTR_SODA_TABLESPACE               	ACI_ATTR_SODA_TABLESPACE        
#define OCI_ATTR_SODA_STORAGE_INIT_SIZE        	ACI_ATTR_SODA_STORAGE_INIT_SIZE 
#define OCI_ATTR_SODA_STORAGE_INC_PCT          	ACI_ATTR_SODA_STORAGE_INC_PCT   
#define OCI_ATTR_SODA_KEY_COL_NAME             	ACI_ATTR_SODA_KEY_COL_NAME      
#define OCI_ATTR_SODA_KEY_SQL_TYPE             	ACI_ATTR_SODA_KEY_SQL_TYPE      
#define OCI_ATTR_SODA_KEY_MAX_LEN              	ACI_ATTR_SODA_KEY_MAX_LEN       
#define OCI_ATTR_SODA_KEY_ASSIGN_METHOD        	ACI_ATTR_SODA_KEY_ASSIGN_METHOD 
#define OCI_ATTR_SODA_KEY_SEQ_NAME             	ACI_ATTR_SODA_KEY_SEQ_NAME      
#define OCI_ATTR_SODA_CTNT_COL_NAME            	ACI_ATTR_SODA_CTNT_COL_NAME     
#define OCI_ATTR_SODA_CTNT_SQL_TYPE            	ACI_ATTR_SODA_CTNT_SQL_TYPE     
#define OCI_ATTR_SODA_CTNT_MAX_LEN             	ACI_ATTR_SODA_CTNT_MAX_LEN      
#define OCI_ATTR_SODA_CTNT_VALIDATION          	ACI_ATTR_SODA_CTNT_VALIDATION   
#define OCI_ATTR_SODA_CTNT_COMPRESS            	ACI_ATTR_SODA_CTNT_COMPRESS     
#define OCI_ATTR_SODA_CTNT_CACHE               	ACI_ATTR_SODA_CTNT_CACHE        
#define OCI_ATTR_SODA_CTNT_ENCRYPT             	ACI_ATTR_SODA_CTNT_ENCRYPT      
#define OCI_ATTR_SODA_CTNT_TABLESPACE          	ACI_ATTR_SODA_CTNT_TABLESPACE   
#define OCI_ATTR_SODA_VERSION_COL_NAME         	ACI_ATTR_SODA_VERSION_COL_NAME  
#define OCI_ATTR_SODA_VERSION_METHOD           	ACI_ATTR_SODA_VERSION_METHOD    
#define OCI_ATTR_SODA_MODTIME_COL_NAME         	ACI_ATTR_SODA_MODTIME_COL_NAME  
#define OCI_ATTR_SODA_MODTIME_INDEX            	ACI_ATTR_SODA_MODTIME_INDEX     
#define OCI_ATTR_SODA_CRTIME_COL_NAME          	ACI_ATTR_SODA_CRTIME_COL_NAME   
#define OCI_ATTR_SODA_MTYPE_COL_NAME           	ACI_ATTR_SODA_MTYPE_COL_NAME    
#define OCI_ATTR_SODA_READONLY                 	ACI_ATTR_SODA_READONLY          
#define OCI_ATTR_SODA_KEY                       ACI_ATTR_SODA_KEY                
#define OCI_ATTR_SODA_LASTMOD_TIMESTAMP        	ACI_ATTR_SODA_LASTMOD_TIMESTAMP 
#define OCI_ATTR_SODA_CREATE_TIMESTAMP         	ACI_ATTR_SODA_CREATE_TIMESTAMP  
#define OCI_ATTR_SODA_VERSION                  	ACI_ATTR_SODA_VERSION           
#define OCI_ATTR_SODA_CONTENT                  	ACI_ATTR_SODA_CONTENT           
#define OCI_ATTR_SODA_JSON_CHARSET_ID          	ACI_ATTR_SODA_JSON_CHARSET_ID   
#define OCI_ATTR_SODA_DETECT_JSON_ENC          	ACI_ATTR_SODA_DETECT_JSON_ENC   
#define OCI_ATTR_SODA_MEDIA_TYPE               	ACI_ATTR_SODA_MEDIA_TYPE        
#define OCI_ATTR_SODA_CTNT_FORMAT              	ACI_ATTR_SODA_CTNT_FORMAT       
#define OCI_ATTR_SODA_FILTER                   	ACI_ATTR_SODA_FILTER            
#define OCI_ATTR_SODA_SKIP                      ACI_ATTR_SODA_SKIP                      
#define OCI_ATTR_SODA_LIMIT                    	ACI_ATTR_SODA_LIMIT             

/*--------------------------- soda ---------------------------------------*/

#define OCI_RESULT_TYPE_SELECT					ACI_RESULT_TYPE_SELECT

/* ------------------------------------------------------------------------- */
//Parsing Syntax Types
#define OCI_NTV_SYNTAX                ACI_NTV_SYNTAX

//(Scrollable Cursor) Fetch Options
#define OCI_FETCH_CURRENT             ACI_FETCH_CURRENT
#define OCI_FETCH_NEXT                ACI_FETCH_NEXT
#define OCI_FETCH_FIRST               ACI_FETCH_FIRST
#define OCI_FETCH_LAST                ACI_FETCH_LAST
#define OCI_FETCH_PRIOR               ACI_FETCH_PRIOR
#define OCI_FETCH_ABSOLUTE            ACI_FETCH_ABSOLUTE
#define OCI_FETCH_RELATIVE            ACI_FETCH_RELATIVE
#define OCI_FETCH_RESERVED_1          ACI_FETCH_RESERVED_1
#define OCI_FETCH_RESERVED_2          ACI_FETCH_RESERVED_2
#define OCI_FETCH_RESERVED_3          ACI_FETCH_RESERVED_3
#define OCI_FETCH_RESERVED_4          ACI_FETCH_RESERVED_4
#define OCI_FETCH_RESERVED_5          ACI_FETCH_RESERVED_5

//Descriptor Types
#define OCI_DTYPE_LOB                 ACI_DTYPE_LOB
#define OCI_DTYPE_FILE                ACI_DTYPE_FILE
#define OCI_DTYPE_PARAM               ACI_DTYPE_PARAM
#define OCI_DTYPE_TIMESTAMP           ACI_DTYPE_TIMESTAMP
#define OCI_DTYPE_TIMESTAMP_TZ        ACI_DTYPE_TIMESTAMP_TZ
#define OCI_DTYPE_TIMESTAMP_LTZ       ACI_DTYPE_TIMESTAMP_LTZ
#define OCI_DTYPE_INTERVAL_DS         ACI_DTYPE_INTERVAL_DS
#define OCI_DTYPE_INTERVAL_YM         ACI_DTYPE_INTERVAL_YM
#define OCI_DTYPE_DATE				  ACI_DTYPE_DATE
#define OCI_DTYPE_JSON				  ACI_DTYPE_JSON
#define OCI_DTYPE_ROWID				  ACI_DTYPE_ROWID
#define OCI_DTYPE_UCB				  ACI_DTYPE_UCB
#define OCI_DTYPE_SERDN				  ACI_DTYPE_SERDN
#define OCI_DTYPE_COMPLEXOBJECTCOMP	  ACI_DTYPE_COMPLEXOBJECTCOMP
#define OCI_DTYPE_AQENQ_OPTIONS		  ACI_DTYPE_AQENQ_OPTIONS
#define OCI_DTYPE_AQDEQ_OPTIONS		  ACI_DTYPE_AQDEQ_OPTIONS
#define OCI_DTYPE_AQMSG_PROPERTIES	  ACI_DTYPE_AQMSG_PROPERTIES
#define OCI_DTYPE_AQAGENT			  ACI_DTYPE_AQAGENT
#define OCI_DTYPE_AQNFY				  ACI_DTYPE_AQNFY
#define OCI_DTYPE_AQLIS_OPTIONS		  ACI_DTYPE_AQLIS_OPTIONS
#define OCI_DTYPE_AQLIS_MSG_PROPERTIES		ACI_DTYPE_AQLIS_MSG_PROPERTIES
#define OCI_DTYPE_CHDES				  ACI_DTYPE_CHDES
#define OCI_DTYPE_TABLE_CHDES		  ACI_DTYPE_TABLE_CHDES
#define OCI_DTYPE_ROWCHDES			  ACI_DTYPE_ROWCHDES
#define OCI_DTYPE_SNAP				  ACI_DTYPE_SNAP

// ACI Advanced Queuing
#define OCI_ENQ_IMMEDIATE			ACI_ENQ_IMMEDIATE
#define OCI_ENQ_ON_COMMIT			ACI_ENQ_ON_COMMIT
#define	OCI_MSG_PERSISTENT			ACI_MSG_PERSISTENT
#define	OCI_MSG_BUFFERED			ACI_MSG_BUFFERED
#define	OCI_MSG_PERSISTENT_OR_BUFFERED	ACI_MSG_PERSISTENT_OR_BUFFERED
#define	OCI_ATTR_MSG_DELIVERY_MODE		ACI_ATTR_MSG_DELIVERY_MODE
#define	OCI_MSG_PERSISTENT_OR_BUFFERED	ACI_MSG_PERSISTENT_OR_BUFFERED

//ACI Parameter Types
#define OCI_PTYPE_TABLE               ACI_PTYPE_TABLE
#define OCI_PTYPE_PROC                ACI_PTYPE_PROC
#define OCI_PTYPE_FUNC                ACI_PTYPE_FUNC
#define OCI_PTYPE_PKG                 ACI_PTYPE_PKG

//Descriptor Definitions
#define OCIParam                      ACIParam
#define OCILobLocator                 ACILobLocator
#define OCIDateTime                   ACIDateTime
#define OCIInterval                   ACIInterval
#define OCISnapshot                   ACISnapshot
#define OCIDescribe                   ACIDescribe
#define OCIRowid					  ACIRowid
#define OCIJson						  ACIJson
#define OCIString					  ACIString
#define OCIType						  ACIType
#define	OCIUcb						  ACIUcb
#define	OCIserverDNs				  ACIserverDNs
#define	OCIComplexObjectComp		  ACIComplexObjectComp
#define	OCIAQEnqOptions				  ACIAQEnqOptions
#define	OCIAQDeqOptions				  ACIAQDeqOptions
#define	OCIAQMsgProperties			  ACIAQMsgProperties
#define	OCIAQAgent					  ACIAQAgent
#define	OCIAQNotify					  ACIAQNotify
#define	OCIAQListenOpts				  ACIAQListenOpts
#define	OCIAQLisMsgProps			  ACIAQLisMsgProps

/*--------------------- OCI Thread Object Definitions------------------------*/
#define OCIThreadContext ACIThreadContext
#define OCIThreadMutex   ACIThreadMutex
#define OCIThreadKey     ACIThreadKey
#define OCIThreadId      ACIThreadId
#define OCIThreadHandle  ACIThreadHandle

//Piece Definitions
#define OCI_ONE_PIECE                 ACI_ONE_PIECE
#define OCI_FIRST_PIECE               ACI_FIRST_PIECE
#define OCI_LAST_PIECE                ACI_LAST_PIECE
#define OCI_NEXT_PIECE                ACI_NEXT_PIECE

//Object Ptr Types
#define OCI_ATTR_OBJ_NAME			  ACI_ATTR_OBJ_NAME
#define OCI_OTYPE_NAME                ACI_OTYPE_NAME
#define OCI_OTYPE_REF				  ACI_OTYPE_REF
#define OCI_OTYPE_PTR				  ACI_OTYPE_PTR

#define OCI_ATTR_LIST_ARGUMENTS       ACI_ATTR_LIST_ARGUMENTS
#define OCI_ATTR_LIST_SUBPROGRAMS     ACI_ATTR_LIST_SUBPROGRAMS
#define OCI_ATTR_NUM_PARAMS           ACI_ATTR_NUM_PARAMS
#define OCI_ATTR_PTYPE                ACI_ATTR_PTYPE

#define OCI_NUMBER_SIZE               ACI_NUMBER_SIZE

// direct path
#define OCI_DIRPATH_INPUT_STREAM	  ACI_DIRPATH_INPUT_STREAM
#define OCI_DIRPATH_COL_COMPLETE      ACI_DIRPATH_COL_COMPLETE
#define OCI_DIRPATH_COL_NULL          ACI_DIRPATH_COL_NULL
#define OCI_DIRPATH_COL_PARTIAL       ACI_DIRPATH_COL_PARTIAL

/*--------------------------- ACI Statement Types ---------------------------*/
#define  OCI_STMT_UNKNOWN             ACI_STMT_UNKNOWN
#define  OCI_STMT_SELECT              ACI_STMT_SELECT
#define  OCI_STMT_UPDATE              ACI_STMT_UPDATE
#define  OCI_STMT_DELETE              ACI_STMT_DELETE
#define  OCI_STMT_INSERT              ACI_STMT_INSERT
#define  OCI_STMT_CREATE              ACI_STMT_CREATE
#define  OCI_STMT_DROP                ACI_STMT_DROP
#define  OCI_STMT_ALTER               ACI_STMT_ALTER
#define  OCI_STMT_BEGIN               ACI_STMT_BEGIN
#define  OCI_STMT_DECLARE             ACI_STMT_DECLARE
#define  OCI_STMT_CALL                ACI_STMT_CALL
#define  OCI_STMT_MERGE				  ACI_STMT_MERGE
/*---------------------------------------------------------------------------*/

/*--------------------------- ACI Parameter Types ---------------------------*/
#define OCI_PTYPE_UNK                 ACI_PTYPE_UNK
#define OCI_PTYPE_TABLE               ACI_PTYPE_TABLE
#define OCI_PTYPE_VIEW                ACI_PTYPE_VIEW
#define OCI_PTYPE_PROC                ACI_PTYPE_PROC
#define OCI_PTYPE_FUNC                ACI_PTYPE_FUNC
#define OCI_PTYPE_PKG                 ACI_PTYPE_PKG
#define OCI_PTYPE_TYPE                ACI_PTYPE_TYPE
#define OCI_PTYPE_SYN                 ACI_PTYPE_SYN
#define OCI_PTYPE_SEQ                 ACI_PTYPE_SEQ
#define OCI_PTYPE_COL                 ACI_PTYPE_COL
#define OCI_PTYPE_ARG                 ACI_PTYPE_ARG
#define OCI_PTYPE_LIST                ACI_PTYPE_LIST
#define OCI_PTYPE_TYPE_ATTR           ACI_PTYPE_TYPE_ATTR
#define OCI_PTYPE_TYPE_COLL           ACI_PTYPE_TYPE_COLL
#define OCI_PTYPE_TYPE_METHOD         ACI_PTYPE_TYPE_METHOD
#define OCI_PTYPE_TYPE_ARG            ACI_PTYPE_TYPE_ARG
#define OCI_PTYPE_TYPE_RESULT         ACI_PTYPE_TYPE_RESULT
#define OCI_PTYPE_SCHEMA              ACI_PTYPE_SCHEMA
#define OCI_PTYPE_DATABASE            ACI_PTYPE_DATABASE
#define OCI_PTYPE_RULE                ACI_PTYPE_RULE
#define OCI_PTYPE_RULE_SET            ACI_PTYPE_RULE_SET
#define OCI_PTYPE_EVALUATION_CONTEXT  ACI_PTYPE_EVALUATION_CONTEXT
#define OCI_PTYPE_TABLE_ALIAS         ACI_PTYPE_TABLE_ALIAS
#define OCI_PTYPE_VARIABLE_TYPE       ACI_PTYPE_VARIABLE_TYPE
#define OCI_PTYPE_NAME_VALUE          ACI_PTYPE_NAME_VALUE

/*---------------------------------------------------------------------------*/

/*------------------------ Transaction Start Flags --------------------------*/
#define OCI_TRANS_NEW                 ACI_TRANS_NEW
#define OCI_TRANS_JOIN                ACI_TRANS_JOIN
#define OCI_TRANS_RESUME              ACI_TRANS_RESUME
#define OCI_TRANS_STARTMASK           ACI_TRANS_STARTMASK

#define OCI_TRANS_READONLY            ACI_TRANS_READONLY
#define OCI_TRANS_READWRITE           ACI_TRANS_READWRITE
#define OCI_TRANS_SERIALIZABLE        ACI_TRANS_SERIALIZABLE
/* starts a serializable transaction */
#define OCI_TRANS_ISOLMASK            ACI_TRANS_ISOLMASK

#define OCI_TRANS_LOOSE               ACI_TRANS_LOOSE
#define OCI_TRANS_TIGHT               ACI_TRANS_TIGHT
#define OCI_TRANS_TYPEMASK            ACI_TRANS_TYPEMASK

#define OCI_TRANS_NOMIGRATE           ACI_TRANS_NOMIGRATE
#define OCI_TRANS_SEPARABLE           ACI_TRANS_SEPARABLE
#define OCI_TRANS_OTSRESUME           ACI_TRANS_OTSRESUME


/*---------------------------------------------------------------------------*/

/*------------------------ Transaction End Flags ----------------------------*/
#define OCI_TRANS_TWOPHASE            ACI_TRANS_TWOPHASE
#define OCI_TRANS_WRITEBATCH          ACI_TRANS_WRITEBATCH
#define OCI_TRANS_WRITEIMMED          ACI_TRANS_WRITEIMMED
#define OCI_TRANS_WRITEWAIT           ACI_TRANS_WRITEWAIT
#define OCI_TRANS_WRITENOWAIT         ACI_TRANS_WRITENOWAIT
/*---------------------------------------------------------------------------*/

#define OCI_ATTR_CHAR_USED	ACI_ATTR_CHAR_USED                 
#define OCI_ATTR_CHAR_SIZE	ACI_ATTR_CHAR_SIZE                 

/*--------------------------------LOB types ---------------------------------*/
#define OCI_TEMP_BLOB	ACI_TEMP_BLOB                
#define OCI_TEMP_CLOB	ACI_TEMP_CLOB   
#define OCI_TEMP_BFILE	ACI_TEMP_BFILE
#define OCI_ATTR_LOB_TYPE ACI_ATTR_LOB_TYPE
/*---------------------------------------------------------------------------*/

/*-------------------------- LOB open modes ---------------------------------*/
#define OCI_LOB_READONLY	ACI_LOB_READONLY
#define OCI_LOB_READWRITE	ACI_LOB_READWRITE
#define OCI_LOB_WRITEONLY	ACI_LOB_WRITEONLY
#define OCI_FILE_READONLY	ACI_FILE_READONLY
/*---------------------------------------------------------------------------*/

/*--------------------------- FILE open modes -------------------------------*/
#define OCI_FILE_READ_ONLY             ACI_FILE_READ_ONLY 
#define OCI_FILE_READONLY			   ACI_FILE_READONLY
#define OCI_FILE_READ_WRITE			   ACI_FILE_READ_WRITE
/*---------------------------------------------------------------------------*/

/*---------------------- LOB buffer flush modes ------------------------------*/
#define OCI_LOB_BUFFER_FREE			   ACI_LOB_BUFFER_FREE
#define OCI_LOB_BUFFER_NOFREE		   ACI_LOB_BUFFER_NOFREE
/*-----------------------------------------------------------------------------*/

/*-------------------------- OBJECT Duration --------------------------------*/
#define  OCIDuration	ACIDuration

#define  OCI_DURATION_INVALID	ACI_DURATION_INVALID                     
#define  OCI_DURATION_BEGIN		ACI_DURATION_BEGIN
#define  OCI_DURATION_SESSION	ACI_DURATION_SESSION
#define  OCI_DURATION_CALL		ACI_DURATION_CALL
#define  OCI_DURATION_LAST		ACI_DURATION_LAST
/*---------------------------------------------------------------------------*/

/*-----------------------Dynamic Callback Function Pointers------------------*/
#define  OCICallbackInBind	 ACICallbackInBind  
#define  OCICallbackOutBind  ACICallbackOutBind 
#define  OCICallbackDefine   ACICallbackDefine  
#define  OCIUserCallback     ACIUserCallback    
#define  OCIEnvCallbackType  ACIEnvCallbackType 
#define  OCICallbackLobRead  ACICallbackLobRead 
#define  OCICallbackLobRead2  ACICallbackLobRead2
#define  OCICallbackLobWrite ACICallbackLobWrite
#define  OCICallbackLobWrite2 ACICallbackLobWrite2
#define  OCICallbackAQEnq    ACICallbackAQEnq   
#define  OCICallbackAQDeq    ACICallbackAQDeq  
#define  OCICallbackStmtCache ACICallbackStmtCache
/*---------------------------------------------------------------------------*/

/*------------------------Bind and Define Options----------------------------*/
#define  OCI_DATA_AT_EXEC  ACI_DATA_AT_EXEC
#define  OCI_DYNAMIC_FETCH ACI_DYNAMIC_FETCH
/*---------------------------------------------------------------------------*/


/*--------------------------Failover Callback Structure ---------------------*/
#define  OCICallbackFailover	ACICallbackFailover
#define  OCIFocbkStruct			ACIFocbkStruct
/*---------------------------------------------------------------------------*/

/*--------------------------HA Callback Structure ---------------------*/
#define  OCIEventCallback	ACIEventCallback
/*---------------------------------------------------------------------------*/

/*--------------------------ACISessionGet type ------------------------------*/
#define  OCI_SESSGET_CPOOL         ACI_SESSGET_CPOOL
#define	 OCI_SESSGET_SPOOL		   ACI_SESSGET_SPOOL
#define  OCI_SESSGET_STMTCACHE     ACI_SESSGET_STMTCACHE
#define  OCI_SESSGET_SPOOL_MATCHANY			ACI_SESSGET_SPOOL_MATCHANY
#define  OCI_SESSGET_MULTIPROPERTY_TAG		ACI_SESSGET_MULTIPROPERTY_TAG
/*---------------------------------------------------------------------------*/

/*--------------------------ACISessionRelease type ------------------------------*/
#define  OCI_SESSRLS_RETAG					ACI_SESSRLS_RETAG
#define	 OCI_SESSRLS_DROPSESS				ACI_SESSRLS_DROPSESS
#define  OCI_SESSRLS_MULTIPROPERTY_TAG		ACI_SESSRLS_MULTIPROPERTY_TAG
/*---------------------------------------------------------------------------*/

/*--------------------------------- ACILogon2 Modes -------------------------*/

#define OCI_LOGON2_SPOOL    ACI_LOGON2_SPOOL
#define OCI_LOGON2_CPOOL    ACI_LOGON2_CPOOL
#define OCI_LOGON2_STMTCACHE     ACI_LOGON2_STMTCACHE
/*---------------------------------------------------------------------------*/

/*------------------------ACIConnectionpoolCreate Modes----------------------*/

#define OCI_CPOOL_REINITIALIZE ACI_CPOOL_REINITIALIZE

/*---------------------------------------------------------------------------*/

/*---------------------ACIStmtRelease Modes----------------------------------*/
#define OCI_STRLS_CACHE_DELETE ACI_STRLS_CACHE_DELETE


#define oraub8 aciub8
#define orasb8 acisb8

/* ------------------------ Encoding & NLS Attributes ---------------------- */
#define OCI_ATTR_ENV_CHARSET_ID		ACI_ATTR_ENV_CHARSET_ID
#define OCI_ATTR_CHARSET_ID			ACI_ATTR_CHARSET_ID
#define OCI_ATTR_CHARSET_FORM		ACI_ATTR_CHARSET_FORM
#define OCI_NLS_MAXBUFSZ			ACI_NLS_MAXBUFSZ
#define OCI_NLS_LANGUAGE			ACI_NLS_LANGUAGE
#define OCI_NLS_TERRITORY			ACI_NLS_TERRITORY
#define OCI_UTF16ID					ACI_UTF16ID
#define OCI_UTF16                   ACI_UTF16
#define OCI_NLS_CHARSET_ID          ACI_NLS_CHARSET_ID
#define OCI_NLS_CHARSET_MAXBYTESZ   ACI_NLS_CHARSET_MAXBYTESZ
#define OCI_NLS_CHARSET_FIXEDWIDTH	ACI_NLS_CHARSET_FIXEDWIDTH
#define OCI_NLS_CHARACTER_SET		ACI_NLS_CHARACTER_SET

#define OCI_NLS_CS_IANA_TO_ORA       ACI_NLS_CS_IANA_TO_ST
#define OCI_NLS_CS_ORA_TO_IANA       ACI_NLS_CS_ST_TO_IANA
#define OCI_NLS_LANG_ISO_TO_ORA      ACI_NLS_LANG_ISO_TO_ST
#define OCI_NLS_LANG_ORA_TO_ISO      ACI_NLS_LANG_ST_TO_ISO
#define OCI_NLS_TERR_ISO_TO_ORA      ACI_NLS_TERR_ISO_TO_ST
#define OCI_NLS_TERR_ORA_TO_ISO      ACI_NLS_TERR_ST_TO_ISO
#define OCI_NLS_TERR_ISO3_TO_ORA     ACI_NLS_TERR_ISO3_TO_ST
#define OCI_NLS_TERR_ORA_TO_ISO3     ACI_NLS_TERR_ST_TO_ISO3

/*-------------------------------------------------------------------------*/
/*-------------values for action parameter to OCIDirPathDataSave ----------*/
#define OCI_DIRPATH_DATASAVE_SAVEONLY	ACI_DIRPATH_DATASAVE_SAVEONLY
#define OCI_DIRPATH_DATASAVE_FINISH		ACI_DIRPATH_DATASAVE_FINISH
/*-------------------------------------------------------------------------*/

/*------------Interval Error Codes used by ACIInterCheck()-----------------*/
#define   OCI_INTER_INVALID_DAY			ACI_INTER_INVALID_DAY         
#define   OCI_INTER_DAY_BELOW_VALID		ACI_INTER_DAY_BELOW_VALID     
#define   OCI_INTER_INVALID_MONTH		ACI_INTER_INVALID_MONTH      
#define   OCI_INTER_MONTH_BELOW_VALID	ACI_INTER_MONTH_BELOW_VALID   
#define   OCI_INTER_INVALID_YEAR		ACI_INTER_INVALID_YEAR        
#define   OCI_INTER_YEAR_BELOW_VALID	ACI_INTER_YEAR_BELOW_VALID    
#define   OCI_INTER_INVALID_HOUR		ACI_INTER_INVALID_HOUR        
#define   OCI_INTER_HOUR_BELOW_VALID	ACI_INTER_HOUR_BELOW_VALID    
#define   OCI_INTER_INVALID_MINUTE		ACI_INTER_INVALID_MINUTE     
#define   OCI_INTER_MINUTE_BELOW_VALID	ACI_INTER_MINUTE_BELOW_VALID  
#define   OCI_INTER_INVALID_SECOND		ACI_INTER_INVALID_SECOND      
#define   OCI_INTER_SECOND_BELOW_VALID	ACI_INTER_SECOND_BELOW_VALID  
#define   OCI_INTER_INVALID_FRACSEC		ACI_INTER_INVALID_FRACSEC     
#define   OCI_INTER_FRACSEC_BELOW_VALID	ACI_INTER_FRACSEC_BELOW_VALID
/*-------------------------------------------------------------------------*/

/*------------------------Piece Information----------------------------------*/
#define OCI_PARAM_IN ACI_PARAM_IN                                    /* in parameter */
#define OCI_PARAM_OUT ACI_PARAM_OUT                                  /* out parameter */
/*---------------------------------------------------------------------------*/

/*------------------------Authentication Modes-------------------------------*/
#define OCI_STMT_CACHE ACI_STMT_CACHE
#define OCI_AUTH         ACI_AUTH
#define OCI_CPW_SYSDBA   ACI_CPW_SYSDBA
#define OCI_CPW_SYSOPER  ACI_CPW_SYSOPER
#define OCI_CPW_SYSASM   ACI_CPW_SYSASM
#define OCI_CPW_SYSBKP   ACI_CPW_SYSBKP
#define OCI_CPW_SYSDGD   ACI_CPW_SYSDGD
#define OCI_CPW_SYSKMT   ACI_CPW_SYSKMT

#define OCI_MIGRATE         ACI_MIGRATE
#define OCI_SYSDBA          ACI_SYSDBA
#define OCI_SYSOPER         ACI_SYSOPER
#define OCI_PRELIM_AUTH     ACI_PRELIM_AUTH
#define OCIP_ICACHE         ACIP_ICACHE
#define OCI_AUTH_RESERVED_1 ACI_AUTH_RESERVED_1
#define OCI_STATELESS_CALL  ACI_STATELESS_CALL
#define OCI_STATELESS_TXN   ACI_STATELESS_TXN
#define OCI_STATELESS_APP   ACI_STATELESS_APP
/*---------------------------------------------------------------------------*/

//********************************shut down Modes*******************************

#define OCI_DBSHUTDOWN_IMMEDIATE						ACI_DBSHUTDOWN_IMMEDIATE
#define OCI_DBSHUTDOWN_TRANSACTIONAL					ACI_DBSHUTDOWN_TRANSACTIONAL
#define OCI_DBSHUTDOWN_ABORT							ACI_DBSHUTDOWN_ABORT
#define OCI_DBSHUTDOWN_FINAL							ACI_DBSHUTDOWN_FINAL
#define OCI_DBSHUTDOWN_TRANSACTIONAL_LOCAL				ACI_DBSHUTDOWN_TRANSACTIONAL_LOCAL

//********************************shut down Modes*******************************