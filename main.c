#include "libbamboo.h"
#include <stdint.h>
#include <stdio.h>

#define PAYLOAD_LENGTH 5
#define KEY_LENGTH 32 // TODO: define this in the header
int main(){

  uint8_t out[MAX_ENTRY_SIZE] = {0};
  uint8_t payload[PAYLOAD_LENGTH] = {1,2,3,4,5};
  uint8_t secret_key[KEY_LENGTH] = { 
    197, 236, 75, 1, 28, 156, 231, 168, 
    29, 26, 12, 113, 0, 150, 235, 94, 
    140, 223, 220, 213, 102, 242, 213, 42, 
    128, 46, 137, 204, 44, 53, 206, 8
  };
  
  uint8_t public_key[KEY_LENGTH] = {
    221, 153, 125, 189, 92, 63, 192, 146, 
    29, 154, 178, 208, 108, 47, 58, 74, 
    149, 140, 115, 129, 117, 166, 223, 169, 
    171, 72, 94, 32, 190, 154, 67, 189
  };

  PublishEd25519Blake2bEntryArgs args = {
    .out = out,
    .out_length = MAX_ENTRY_SIZE,
    .payload_bytes = payload,
    .payload_length = PAYLOAD_LENGTH,
    .public_key_bytes = public_key,
    .public_key_length = KEY_LENGTH,
    .secret_key_bytes = secret_key,
    .secret_key_length = KEY_LENGTH,
    .backlink_bytes = NULL,
    .backlink_length =  0,
    .lipmaalink_bytes = NULL,
    .lipmaalink_length =  0,
    .is_end_of_feed = false,
    .last_seq_num = 0
  };

  intptr_t result = publish_ed25519_blake2b_entry(&args);
  printf("result %li \n", result);

  for (intptr_t i = 0; i < args.out_length; i++){
    printf("%x", out[i]);
  }
  printf("\n");
}
