/******************************************************************************
 * @file    ble_gatt_aci.c
 * @author  MCD Application Team
 * @date    15 January 2019
 * @brief   Source file for ble api STM32WB (gatt_aci)
 *          Auto-generated file: do not edit!
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under Ultimate Liberty license
 * SLA0044, the "License"; You may not use this file except in compliance with
 * the License. You may obtain a copy of the License at:
 *                             www.st.com/SLA0044
 *
 ******************************************************************************
 */

#include "ble_gatt_aci.h"

tBleStatus aci_gatt_init(void)
{
  struct hci_request rq;
  tBleStatus status = 0;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x101;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_add_service(uint8_t Service_UUID_Type,
                                Service_UUID_t *Service_UUID,
                                uint8_t Service_Type,
                                uint8_t Max_Attribute_Records,
                                uint16_t *Service_Handle)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_add_service_cp0 *cp0 = (aci_gatt_add_service_cp0*)(cmd_buffer);
  aci_gatt_add_service_cp1 *cp1 = (aci_gatt_add_service_cp1*)(cmd_buffer + 1 + (Service_UUID_Type == 1 ? 2 : (Service_UUID_Type == 2 ? 16 : 0)));
  aci_gatt_add_service_rp0 resp;
  Osal_MemSet(&resp, 0, sizeof(resp));
  int index_input = 0;
  cp0->Service_UUID_Type = htob(Service_UUID_Type, 1);
  index_input += 1;
  /* var_len_data input */
  {
    uint8_t size;
    switch (Service_UUID_Type) {
      case 1: size = 2; break;
      case 2: size = 16; break;
      default: return BLE_STATUS_ERROR;
    }
    Osal_MemCpy((void *) &cp0->Service_UUID, (const void *) Service_UUID, size);
    index_input += size;
    {
      cp1->Service_Type = htob(Service_Type, 1);
    }
    index_input += 1;
    {
      cp1->Max_Attribute_Records = htob(Max_Attribute_Records, 1);
    }
    index_input += 1;
  }
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x102;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &resp;
  rq.rlen = sizeof(resp);
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (resp.Status) 
  {
    return resp.Status;
  }
  *Service_Handle = btoh(resp.Service_Handle, 2);
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_include_service(uint16_t Service_Handle,
                                    uint16_t Include_Start_Handle,
                                    uint16_t Include_End_Handle,
                                    uint8_t Include_UUID_Type,
                                    Include_UUID_t *Include_UUID,
                                    uint16_t *Include_Handle)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_include_service_cp0 *cp0 = (aci_gatt_include_service_cp0*)(cmd_buffer);
  aci_gatt_include_service_rp0 resp;
  Osal_MemSet(&resp, 0, sizeof(resp));
  int index_input = 0;
  int uuid_size = (Include_UUID_Type == 2) ? 16 : 2;
  cp0->Service_Handle = htob(Service_Handle, 2);
  index_input += 2;
  cp0->Include_Start_Handle = htob(Include_Start_Handle, 2);
  index_input += 2;
  cp0->Include_End_Handle = htob(Include_End_Handle, 2);
  index_input += 2;
  cp0->Include_UUID_Type = htob(Include_UUID_Type, 1);
  index_input += 1;
  Osal_MemCpy((void *) &cp0->Include_UUID, (const void *) Include_UUID, uuid_size);
  index_input += uuid_size;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x103;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &resp;
  rq.rlen = sizeof(resp);
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (resp.Status) 
  {
    return resp.Status;
  }
  *Include_Handle = btoh(resp.Include_Handle, 2);
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_add_char(uint16_t Service_Handle,
                             uint8_t Char_UUID_Type,
                             Char_UUID_t *Char_UUID,
                             uint16_t Char_Value_Length,
                             uint8_t Char_Properties,
                             uint8_t Security_Permissions,
                             uint8_t GATT_Evt_Mask,
                             uint8_t Enc_Key_Size,
                             uint8_t Is_Variable,
                             uint16_t *Char_Handle)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_add_char_cp0 *cp0 = (aci_gatt_add_char_cp0*)(cmd_buffer);
  aci_gatt_add_char_cp1 *cp1 = (aci_gatt_add_char_cp1*)(cmd_buffer + 2 + 1 + (Char_UUID_Type == 1 ? 2 : (Char_UUID_Type == 2 ? 16 : 0)));
  aci_gatt_add_char_rp0 resp;
  Osal_MemSet(&resp, 0, sizeof(resp));
  int index_input = 0;
  cp0->Service_Handle = htob(Service_Handle, 2);
  index_input += 2;
  cp0->Char_UUID_Type = htob(Char_UUID_Type, 1);
  index_input += 1;
  /* var_len_data input */
  {
    uint8_t size;
    switch (Char_UUID_Type) {
      case 1: size = 2; break;
      case 2: size = 16; break;
      default: return BLE_STATUS_ERROR;
    }
    Osal_MemCpy((void *) &cp0->Char_UUID, (const void *) Char_UUID, size);
    index_input += size;
    {
      cp1->Char_Value_Length = htob(Char_Value_Length, 2);
    }
    index_input += 2;
    {
      cp1->Char_Properties = htob(Char_Properties, 1);
    }
    index_input += 1;
    {
      cp1->Security_Permissions = htob(Security_Permissions, 1);
    }
    index_input += 1;
    {
      cp1->GATT_Evt_Mask = htob(GATT_Evt_Mask, 1);
    }
    index_input += 1;
    {
      cp1->Enc_Key_Size = htob(Enc_Key_Size, 1);
    }
    index_input += 1;
    {
      cp1->Is_Variable = htob(Is_Variable, 1);
    }
    index_input += 1;
  }
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x104;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &resp;
  rq.rlen = sizeof(resp);
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (resp.Status) 
  {
    return resp.Status;
  }
  *Char_Handle = btoh(resp.Char_Handle, 2);
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_add_char_desc(uint16_t Service_Handle,
                                  uint16_t Char_Handle,
                                  uint8_t Char_Desc_Uuid_Type,
                                  Char_Desc_Uuid_t *Char_Desc_Uuid,
                                  uint8_t Char_Desc_Value_Max_Len,
                                  uint8_t Char_Desc_Value_Length,
                                  uint8_t Char_Desc_Value[],
                                  uint8_t Security_Permissions,
                                  uint8_t Access_Permissions,
                                  uint8_t GATT_Evt_Mask,
                                  uint8_t Enc_Key_Size,
                                  uint8_t Is_Variable,
                                  uint16_t *Char_Desc_Handle)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_add_char_desc_cp0 *cp0 = (aci_gatt_add_char_desc_cp0*)(cmd_buffer);
  aci_gatt_add_char_desc_cp1 *cp1 = (aci_gatt_add_char_desc_cp1*)(cmd_buffer + 2 + 2 + 1 + (Char_Desc_Uuid_Type == 1 ? 2 : (Char_Desc_Uuid_Type == 2 ? 16 : 0)));
  aci_gatt_add_char_desc_cp2 *cp2 = (aci_gatt_add_char_desc_cp2*)(cmd_buffer + 2 + 2 + 1 + (Char_Desc_Uuid_Type == 1 ? 2 : (Char_Desc_Uuid_Type == 2 ? 16 : 0)) + 1 + 1 + Char_Desc_Value_Length * (sizeof(uint8_t)));
  aci_gatt_add_char_desc_rp0 resp;
  Osal_MemSet(&resp, 0, sizeof(resp));
  int index_input = 0;
  cp0->Service_Handle = htob(Service_Handle, 2);
  index_input += 2;
  cp0->Char_Handle = htob(Char_Handle, 2);
  index_input += 2;
  cp0->Char_Desc_Uuid_Type = htob(Char_Desc_Uuid_Type, 1);
  index_input += 1;
  /* var_len_data input */
  {
    uint8_t size;
    switch (Char_Desc_Uuid_Type) {
      case 1: size = 2; break;
      case 2: size = 16; break;
      default: return BLE_STATUS_ERROR;
    }
    Osal_MemCpy((void *) &cp0->Char_Desc_Uuid, (const void *) Char_Desc_Uuid, size);
    index_input += size;
    {
      cp1->Char_Desc_Value_Max_Len = htob(Char_Desc_Value_Max_Len, 1);
    }
    index_input += 1;
    {
      cp1->Char_Desc_Value_Length = htob(Char_Desc_Value_Length, 1);
    }
    index_input += 1;
    Osal_MemCpy((void *) &cp1->Char_Desc_Value, (const void *) Char_Desc_Value, Char_Desc_Value_Length);
    index_input += Char_Desc_Value_Length;
    {
      cp2->Security_Permissions = htob(Security_Permissions, 1);
    }
    index_input += 1;
    {
      cp2->Access_Permissions = htob(Access_Permissions, 1);
    }
    index_input += 1;
    {
      cp2->GATT_Evt_Mask = htob(GATT_Evt_Mask, 1);
    }
    index_input += 1;
    {
      cp2->Enc_Key_Size = htob(Enc_Key_Size, 1);
    }
    index_input += 1;
    {
      cp2->Is_Variable = htob(Is_Variable, 1);
    }
    index_input += 1;
  }
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x105;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &resp;
  rq.rlen = sizeof(resp);
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (resp.Status) 
  {
    return resp.Status;
  }
  *Char_Desc_Handle = btoh(resp.Char_Desc_Handle, 2);
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_update_char_value(uint16_t Service_Handle,
                                      uint16_t Char_Handle,
                                      uint8_t Val_Offset,
                                      uint8_t Char_Value_Length,
                                      uint8_t Char_Value[])
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_update_char_value_cp0 *cp0 = (aci_gatt_update_char_value_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Service_Handle = htob(Service_Handle, 2);
  index_input += 2;
  cp0->Char_Handle = htob(Char_Handle, 2);
  index_input += 2;
  cp0->Val_Offset = htob(Val_Offset, 1);
  index_input += 1;
  cp0->Char_Value_Length = htob(Char_Value_Length, 1);
  index_input += 1;
  Osal_MemCpy((void *) &cp0->Char_Value, (const void *) Char_Value, Char_Value_Length);
  index_input += Char_Value_Length;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x106;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_del_char(uint16_t Serv_Handle,
                             uint16_t Char_Handle)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_del_char_cp0 *cp0 = (aci_gatt_del_char_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Serv_Handle = htob(Serv_Handle, 2);
  index_input += 2;
  cp0->Char_Handle = htob(Char_Handle, 2);
  index_input += 2;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x107;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_del_service(uint16_t Serv_Handle)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_del_service_cp0 *cp0 = (aci_gatt_del_service_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Serv_Handle = htob(Serv_Handle, 2);
  index_input += 2;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x108;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_del_include_service(uint16_t Serv_Handle,
                                        uint16_t Include_Handle)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_del_include_service_cp0 *cp0 = (aci_gatt_del_include_service_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Serv_Handle = htob(Serv_Handle, 2);
  index_input += 2;
  cp0->Include_Handle = htob(Include_Handle, 2);
  index_input += 2;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x109;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_set_event_mask(uint32_t GATT_Evt_Mask)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_set_event_mask_cp0 *cp0 = (aci_gatt_set_event_mask_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->GATT_Evt_Mask = htob(GATT_Evt_Mask, 4);
  index_input += 4;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x10a;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_exchange_config(uint16_t Connection_Handle)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_exchange_config_cp0 *cp0 = (aci_gatt_exchange_config_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x10b;
  rq.event = 0x0F;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_att_find_info_req(uint16_t Connection_Handle,
                                 uint16_t Start_Handle,
                                 uint16_t End_Handle)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_att_find_info_req_cp0 *cp0 = (aci_att_find_info_req_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Start_Handle = htob(Start_Handle, 2);
  index_input += 2;
  cp0->End_Handle = htob(End_Handle, 2);
  index_input += 2;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x10c;
  rq.event = 0x0F;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_att_find_by_type_value_req(uint16_t Connection_Handle,
                                          uint16_t Start_Handle,
                                          uint16_t End_Handle,
                                          uint16_t UUID,
                                          uint8_t Attribute_Val_Length,
                                          uint8_t Attribute_Val[])
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_att_find_by_type_value_req_cp0 *cp0 = (aci_att_find_by_type_value_req_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Start_Handle = htob(Start_Handle, 2);
  index_input += 2;
  cp0->End_Handle = htob(End_Handle, 2);
  index_input += 2;
  cp0->UUID = htob(UUID, 2);
  index_input += 2;
  cp0->Attribute_Val_Length = htob(Attribute_Val_Length, 1);
  index_input += 1;
  Osal_MemCpy((void *) &cp0->Attribute_Val, (const void *) Attribute_Val, Attribute_Val_Length);
  index_input += Attribute_Val_Length;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x10d;
  rq.event = 0x0F;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_att_read_by_type_req(uint16_t Connection_Handle,
                                    uint16_t Start_Handle,
                                    uint16_t End_Handle,
                                    uint8_t UUID_Type,
                                    UUID_t *UUID)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_att_read_by_type_req_cp0 *cp0 = (aci_att_read_by_type_req_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  int uuid_size = (UUID_Type == 2) ? 16 : 2;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Start_Handle = htob(Start_Handle, 2);
  index_input += 2;
  cp0->End_Handle = htob(End_Handle, 2);
  index_input += 2;
  cp0->UUID_Type = htob(UUID_Type, 1);
  index_input += 1;
  Osal_MemCpy((void *) &cp0->UUID, (const void *) UUID, uuid_size);
  index_input += uuid_size;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x10e;
  rq.event = 0x0F;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_att_read_by_group_type_req(uint16_t Connection_Handle,
                                          uint16_t Start_Handle,
                                          uint16_t End_Handle,
                                          uint8_t UUID_Type,
                                          UUID_t *UUID)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_att_read_by_group_type_req_cp0 *cp0 = (aci_att_read_by_group_type_req_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  int uuid_size = (UUID_Type == 2) ? 16 : 2;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Start_Handle = htob(Start_Handle, 2);
  index_input += 2;
  cp0->End_Handle = htob(End_Handle, 2);
  index_input += 2;
  cp0->UUID_Type = htob(UUID_Type, 1);
  index_input += 1;
  Osal_MemCpy((void *) &cp0->UUID, (const void *) UUID, uuid_size);
  index_input += uuid_size;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x10f;
  rq.event = 0x0F;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_att_prepare_write_req(uint16_t Connection_Handle,
                                     uint16_t Attr_Handle,
                                     uint16_t Val_Offset,
                                     uint8_t Attribute_Val_Length,
                                     uint8_t Attribute_Val[])
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_att_prepare_write_req_cp0 *cp0 = (aci_att_prepare_write_req_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Attr_Handle = htob(Attr_Handle, 2);
  index_input += 2;
  cp0->Val_Offset = htob(Val_Offset, 2);
  index_input += 2;
  cp0->Attribute_Val_Length = htob(Attribute_Val_Length, 1);
  index_input += 1;
  Osal_MemCpy((void *) &cp0->Attribute_Val, (const void *) Attribute_Val, Attribute_Val_Length);
  index_input += Attribute_Val_Length;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x110;
  rq.event = 0x0F;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_att_execute_write_req(uint16_t Connection_Handle,
                                     uint8_t Execute)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_att_execute_write_req_cp0 *cp0 = (aci_att_execute_write_req_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Execute = htob(Execute, 1);
  index_input += 1;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x111;
  rq.event = 0x0F;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_disc_all_primary_services(uint16_t Connection_Handle)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_disc_all_primary_services_cp0 *cp0 = (aci_gatt_disc_all_primary_services_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x112;
  rq.event = 0x0F;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_disc_primary_service_by_uuid(uint16_t Connection_Handle,
                                                 uint8_t UUID_Type,
                                                 UUID_t *UUID)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_disc_primary_service_by_uuid_cp0 *cp0 = (aci_gatt_disc_primary_service_by_uuid_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  int uuid_size = (UUID_Type == 2) ? 16 : 2;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->UUID_Type = htob(UUID_Type, 1);
  index_input += 1;
  Osal_MemCpy((void *) &cp0->UUID, (const void *) UUID, uuid_size);
  index_input += uuid_size;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x113;
  rq.event = 0x0F;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_find_included_services(uint16_t Connection_Handle,
                                           uint16_t Start_Handle,
                                           uint16_t End_Handle)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_find_included_services_cp0 *cp0 = (aci_gatt_find_included_services_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Start_Handle = htob(Start_Handle, 2);
  index_input += 2;
  cp0->End_Handle = htob(End_Handle, 2);
  index_input += 2;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x114;
  rq.event = 0x0F;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_disc_all_char_of_service(uint16_t Connection_Handle,
                                             uint16_t Start_Handle,
                                             uint16_t End_Handle)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_disc_all_char_of_service_cp0 *cp0 = (aci_gatt_disc_all_char_of_service_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Start_Handle = htob(Start_Handle, 2);
  index_input += 2;
  cp0->End_Handle = htob(End_Handle, 2);
  index_input += 2;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x115;
  rq.event = 0x0F;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_disc_char_by_uuid(uint16_t Connection_Handle,
                                      uint16_t Start_Handle,
                                      uint16_t End_Handle,
                                      uint8_t UUID_Type,
                                      UUID_t *UUID)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_disc_char_by_uuid_cp0 *cp0 = (aci_gatt_disc_char_by_uuid_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  int uuid_size = (UUID_Type == 2) ? 16 : 2;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Start_Handle = htob(Start_Handle, 2);
  index_input += 2;
  cp0->End_Handle = htob(End_Handle, 2);
  index_input += 2;
  cp0->UUID_Type = htob(UUID_Type, 1);
  index_input += 1;
  Osal_MemCpy((void *) &cp0->UUID, (const void *) UUID, uuid_size);
  index_input += uuid_size;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x116;
  rq.event = 0x0F;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_disc_all_char_desc(uint16_t Connection_Handle,
                                       uint16_t Char_Handle,
                                       uint16_t End_Handle)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_disc_all_char_desc_cp0 *cp0 = (aci_gatt_disc_all_char_desc_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Char_Handle = htob(Char_Handle, 2);
  index_input += 2;
  cp0->End_Handle = htob(End_Handle, 2);
  index_input += 2;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x117;
  rq.event = 0x0F;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_read_char_value(uint16_t Connection_Handle,
                                    uint16_t Attr_Handle)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_read_char_value_cp0 *cp0 = (aci_gatt_read_char_value_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Attr_Handle = htob(Attr_Handle, 2);
  index_input += 2;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x118;
  rq.event = 0x0F;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_read_using_char_uuid(uint16_t Connection_Handle,
                                         uint16_t Start_Handle,
                                         uint16_t End_Handle,
                                         uint8_t UUID_Type,
                                         UUID_t *UUID)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_read_using_char_uuid_cp0 *cp0 = (aci_gatt_read_using_char_uuid_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  int uuid_size = (UUID_Type == 2) ? 16 : 2;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Start_Handle = htob(Start_Handle, 2);
  index_input += 2;
  cp0->End_Handle = htob(End_Handle, 2);
  index_input += 2;
  cp0->UUID_Type = htob(UUID_Type, 1);
  index_input += 1;
  Osal_MemCpy((void *) &cp0->UUID, (const void *) UUID, uuid_size);
  index_input += uuid_size;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x119;
  rq.event = 0x0F;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_read_long_char_value(uint16_t Connection_Handle,
                                         uint16_t Attr_Handle,
                                         uint16_t Val_Offset)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_read_long_char_value_cp0 *cp0 = (aci_gatt_read_long_char_value_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Attr_Handle = htob(Attr_Handle, 2);
  index_input += 2;
  cp0->Val_Offset = htob(Val_Offset, 2);
  index_input += 2;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x11a;
  rq.event = 0x0F;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_read_multiple_char_value(uint16_t Connection_Handle,
                                             uint8_t Number_of_Handles,
                                             Handle_Entry_t Handle_Entry[])
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_read_multiple_char_value_cp0 *cp0 = (aci_gatt_read_multiple_char_value_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Number_of_Handles = htob(Number_of_Handles, 1);
  index_input += 1;
  Osal_MemCpy((void*) &cp0->Handle_Entry, (const void *) Handle_Entry, Number_of_Handles * (sizeof(Handle_Entry_t)));
  index_input += Number_of_Handles * (sizeof(Handle_Entry_t));
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x11b;
  rq.event = 0x0F;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_write_char_value(uint16_t Connection_Handle,
                                     uint16_t Attr_Handle,
                                     uint8_t Attribute_Val_Length,
                                     uint8_t Attribute_Val[])
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_write_char_value_cp0 *cp0 = (aci_gatt_write_char_value_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Attr_Handle = htob(Attr_Handle, 2);
  index_input += 2;
  cp0->Attribute_Val_Length = htob(Attribute_Val_Length, 1);
  index_input += 1;
  Osal_MemCpy((void *) &cp0->Attribute_Val, (const void *) Attribute_Val, Attribute_Val_Length);
  index_input += Attribute_Val_Length;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x11c;
  rq.event = 0x0F;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_write_long_char_value(uint16_t Connection_Handle,
                                          uint16_t Attr_Handle,
                                          uint16_t Val_Offset,
                                          uint8_t Attribute_Val_Length,
                                          uint8_t Attribute_Val[])
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_write_long_char_value_cp0 *cp0 = (aci_gatt_write_long_char_value_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Attr_Handle = htob(Attr_Handle, 2);
  index_input += 2;
  cp0->Val_Offset = htob(Val_Offset, 2);
  index_input += 2;
  cp0->Attribute_Val_Length = htob(Attribute_Val_Length, 1);
  index_input += 1;
  Osal_MemCpy((void *) &cp0->Attribute_Val, (const void *) Attribute_Val, Attribute_Val_Length);
  index_input += Attribute_Val_Length;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x11d;
  rq.event = 0x0F;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_write_char_reliable(uint16_t Connection_Handle,
                                        uint16_t Attr_Handle,
                                        uint16_t Val_Offset,
                                        uint8_t Attribute_Val_Length,
                                        uint8_t Attribute_Val[])
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_write_char_reliable_cp0 *cp0 = (aci_gatt_write_char_reliable_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Attr_Handle = htob(Attr_Handle, 2);
  index_input += 2;
  cp0->Val_Offset = htob(Val_Offset, 2);
  index_input += 2;
  cp0->Attribute_Val_Length = htob(Attribute_Val_Length, 1);
  index_input += 1;
  Osal_MemCpy((void *) &cp0->Attribute_Val, (const void *) Attribute_Val, Attribute_Val_Length);
  index_input += Attribute_Val_Length;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x11e;
  rq.event = 0x0F;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_write_long_char_desc(uint16_t Connection_Handle,
                                         uint16_t Attr_Handle,
                                         uint16_t Val_Offset,
                                         uint8_t Attribute_Val_Length,
                                         uint8_t Attribute_Val[])
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_write_long_char_desc_cp0 *cp0 = (aci_gatt_write_long_char_desc_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Attr_Handle = htob(Attr_Handle, 2);
  index_input += 2;
  cp0->Val_Offset = htob(Val_Offset, 2);
  index_input += 2;
  cp0->Attribute_Val_Length = htob(Attribute_Val_Length, 1);
  index_input += 1;
  Osal_MemCpy((void *) &cp0->Attribute_Val, (const void *) Attribute_Val, Attribute_Val_Length);
  index_input += Attribute_Val_Length;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x11f;
  rq.event = 0x0F;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_read_long_char_desc(uint16_t Connection_Handle,
                                        uint16_t Attr_Handle,
                                        uint16_t Val_Offset)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_read_long_char_desc_cp0 *cp0 = (aci_gatt_read_long_char_desc_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Attr_Handle = htob(Attr_Handle, 2);
  index_input += 2;
  cp0->Val_Offset = htob(Val_Offset, 2);
  index_input += 2;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x120;
  rq.event = 0x0F;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_write_char_desc(uint16_t Connection_Handle,
                                    uint16_t Attr_Handle,
                                    uint8_t Attribute_Val_Length,
                                    uint8_t Attribute_Val[])
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_write_char_desc_cp0 *cp0 = (aci_gatt_write_char_desc_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Attr_Handle = htob(Attr_Handle, 2);
  index_input += 2;
  cp0->Attribute_Val_Length = htob(Attribute_Val_Length, 1);
  index_input += 1;
  Osal_MemCpy((void *) &cp0->Attribute_Val, (const void *) Attribute_Val, Attribute_Val_Length);
  index_input += Attribute_Val_Length;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x121;
  rq.event = 0x0F;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_read_char_desc(uint16_t Connection_Handle,
                                   uint16_t Attr_Handle)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_read_char_desc_cp0 *cp0 = (aci_gatt_read_char_desc_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Attr_Handle = htob(Attr_Handle, 2);
  index_input += 2;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x122;
  rq.event = 0x0F;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_write_without_resp(uint16_t Connection_Handle,
                                       uint16_t Attr_Handle,
                                       uint8_t Attribute_Val_Length,
                                       uint8_t Attribute_Val[])
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_write_without_resp_cp0 *cp0 = (aci_gatt_write_without_resp_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Attr_Handle = htob(Attr_Handle, 2);
  index_input += 2;
  cp0->Attribute_Val_Length = htob(Attribute_Val_Length, 1);
  index_input += 1;
  Osal_MemCpy((void *) &cp0->Attribute_Val, (const void *) Attribute_Val, Attribute_Val_Length);
  index_input += Attribute_Val_Length;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x123;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_signed_write_without_resp(uint16_t Connection_Handle,
                                              uint16_t Attr_Handle,
                                              uint8_t Attribute_Val_Length,
                                              uint8_t Attribute_Val[])
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_signed_write_without_resp_cp0 *cp0 = (aci_gatt_signed_write_without_resp_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Attr_Handle = htob(Attr_Handle, 2);
  index_input += 2;
  cp0->Attribute_Val_Length = htob(Attribute_Val_Length, 1);
  index_input += 1;
  Osal_MemCpy((void *) &cp0->Attribute_Val, (const void *) Attribute_Val, Attribute_Val_Length);
  index_input += Attribute_Val_Length;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x124;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_confirm_indication(uint16_t Connection_Handle)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_confirm_indication_cp0 *cp0 = (aci_gatt_confirm_indication_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x125;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_write_resp(uint16_t Connection_Handle,
                               uint16_t Attr_Handle,
                               uint8_t Write_status,
                               uint8_t Error_Code,
                               uint8_t Attribute_Val_Length,
                               uint8_t Attribute_Val[])
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_write_resp_cp0 *cp0 = (aci_gatt_write_resp_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Attr_Handle = htob(Attr_Handle, 2);
  index_input += 2;
  cp0->Write_status = htob(Write_status, 1);
  index_input += 1;
  cp0->Error_Code = htob(Error_Code, 1);
  index_input += 1;
  cp0->Attribute_Val_Length = htob(Attribute_Val_Length, 1);
  index_input += 1;
  Osal_MemCpy((void *) &cp0->Attribute_Val, (const void *) Attribute_Val, Attribute_Val_Length);
  index_input += Attribute_Val_Length;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x126;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_allow_read(uint16_t Connection_Handle)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_allow_read_cp0 *cp0 = (aci_gatt_allow_read_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x127;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_set_security_permission(uint16_t Serv_Handle,
                                            uint16_t Attr_Handle,
                                            uint8_t Security_Permissions)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_set_security_permission_cp0 *cp0 = (aci_gatt_set_security_permission_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Serv_Handle = htob(Serv_Handle, 2);
  index_input += 2;
  cp0->Attr_Handle = htob(Attr_Handle, 2);
  index_input += 2;
  cp0->Security_Permissions = htob(Security_Permissions, 1);
  index_input += 1;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x128;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_set_desc_value(uint16_t Serv_Handle,
                                   uint16_t Char_Handle,
                                   uint16_t Char_Desc_Handle,
                                   uint16_t Val_Offset,
                                   uint8_t Char_Desc_Value_Length,
                                   uint8_t Char_Desc_Value[])
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_set_desc_value_cp0 *cp0 = (aci_gatt_set_desc_value_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Serv_Handle = htob(Serv_Handle, 2);
  index_input += 2;
  cp0->Char_Handle = htob(Char_Handle, 2);
  index_input += 2;
  cp0->Char_Desc_Handle = htob(Char_Desc_Handle, 2);
  index_input += 2;
  cp0->Val_Offset = htob(Val_Offset, 2);
  index_input += 2;
  cp0->Char_Desc_Value_Length = htob(Char_Desc_Value_Length, 1);
  index_input += 1;
  Osal_MemCpy((void *) &cp0->Char_Desc_Value, (const void *) Char_Desc_Value, Char_Desc_Value_Length);
  index_input += Char_Desc_Value_Length;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x129;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_read_handle_value(uint16_t Attr_Handle,
                                      uint16_t Offset,
                                      uint16_t Value_Length_Requested,
                                      uint16_t *Length,
                                      uint16_t *Value_Length,
                                      uint8_t Value[])
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_read_handle_value_cp0 *cp0 = (aci_gatt_read_handle_value_cp0*)(cmd_buffer);
  aci_gatt_read_handle_value_rp0 resp;
  Osal_MemSet(&resp, 0, sizeof(resp));
  int index_input = 0;
  cp0->Attr_Handle = htob(Attr_Handle, 2);
  index_input += 2;
  cp0->Offset = htob(Offset, 2);
  index_input += 2;
  cp0->Value_Length_Requested = htob(Value_Length_Requested, 2);
  index_input += 2;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x12a;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &resp;
  rq.rlen = sizeof(resp);
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (resp.Status) 
  {
    return resp.Status;
  }
  *Length = btoh(resp.Length, 2);
  *Value_Length = btoh(resp.Value_Length, 2);
  Osal_MemCpy((void *) Value, (const void *) resp.Value, *Value_Length);
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_update_char_value_ext(uint16_t Conn_Handle_To_Notify,
                                          uint16_t Service_Handle,
                                          uint16_t Char_Handle,
                                          uint8_t Update_Type,
                                          uint16_t Char_Length,
                                          uint16_t Value_Offset,
                                          uint8_t Value_Length,
                                          uint8_t Value[])
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_update_char_value_ext_cp0 *cp0 = (aci_gatt_update_char_value_ext_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Conn_Handle_To_Notify = htob(Conn_Handle_To_Notify, 2);
  index_input += 2;
  cp0->Service_Handle = htob(Service_Handle, 2);
  index_input += 2;
  cp0->Char_Handle = htob(Char_Handle, 2);
  index_input += 2;
  cp0->Update_Type = htob(Update_Type, 1);
  index_input += 1;
  cp0->Char_Length = htob(Char_Length, 2);
  index_input += 2;
  cp0->Value_Offset = htob(Value_Offset, 2);
  index_input += 2;
  cp0->Value_Length = htob(Value_Length, 1);
  index_input += 1;
  Osal_MemCpy((void *) &cp0->Value, (const void *) Value, Value_Length);
  index_input += Value_Length;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x12c;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_deny_read(uint16_t Connection_Handle,
                              uint8_t Error_Code)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_deny_read_cp0 *cp0 = (aci_gatt_deny_read_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Connection_Handle = htob(Connection_Handle, 2);
  index_input += 2;
  cp0->Error_Code = htob(Error_Code, 1);
  index_input += 1;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x12d;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

tBleStatus aci_gatt_set_access_permission(uint16_t Serv_Handle,
                                          uint16_t Attr_Handle,
                                          uint8_t Access_Permissions)
{
  struct hci_request rq;
  uint8_t cmd_buffer[BLE_CMD_MAX_PARAM_LEN];
  aci_gatt_set_access_permission_cp0 *cp0 = (aci_gatt_set_access_permission_cp0*)(cmd_buffer);
  tBleStatus status = 0;
  int index_input = 0;
  cp0->Serv_Handle = htob(Serv_Handle, 2);
  index_input += 2;
  cp0->Attr_Handle = htob(Attr_Handle, 2);
  index_input += 2;
  cp0->Access_Permissions = htob(Access_Permissions, 1);
  index_input += 1;
  Osal_MemSet(&rq, 0, sizeof(rq));
  rq.ogf = 0x3f;
  rq.ocf = 0x12e;
  rq.cparam = cmd_buffer;
  rq.clen = index_input;
  rq.rparam = &status;
  rq.rlen = 1;
  if (hci_send_req(&rq, FALSE) < 0)
    return BLE_STATUS_TIMEOUT;
  if (status) 
  {
    return status;
  }
  return BLE_STATUS_SUCCESS;
}

