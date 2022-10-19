/*!***********************************************************************
*@file aciext.h
*@brief aci扩展定义
*@author yfw
*@date 2011-11-22
*@note
*
*因为aci.h与oracle oci.h的定义是一致的，所以不在aci.h中添加扩展的定义
*其他aci扩展的定义可以在此文件中添加
************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

#ifndef ACI_EXT_H
#define ACI_EXT_H

/*=============================Attribute Types===============================*/
/* 
Note: All attributes are global.  New external attibutes should be added to the end
of the list. Before you add an attribute see if an existing one can be 
used for your handle. 

If you see any holes please use the holes first. 

*/
/*===========================================================================*/
#define ACI_ATTR_INSERT_ROW_ROWID    0xffffff //!< rowid of inserted row
#define ACI_ATTR_FETCH_ROWIDS       0x1000000 //!< rowids of bulkinsert row
#define ACI_SOCK_MARK_LEN	        128

#endif /* ACI_EXT_H */

#ifdef __cplusplus
}
#endif /* __cplusplus */
