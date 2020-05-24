#include "libbamboo.h"
#include <stdint.h>
#include <stdio.h>

#define PAYLOAD_LENGTH 5
#define KEY_LENGTH ED25519_SIZE
int main(){

  uint8_t out[MAX_ENTRY_SIZE] = {0};
  uint8_t payload[PAYLOAD_LENGTH] = {1,2,3,4,5};

  // Set up our keys
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

  // Set up the struct to publish the info to publish an entry
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
    .is_end_of_feed = true,
    .last_seq_num = 0,
    .log_id = 0
  };

  // Publish
  intptr_t result = publish_ed25519_blake2b_entry(&args);

  // Print info
  printf("result %li \n", result);

  for (intptr_t i = 0; i < args.out_length; i++){
    printf("%x", out[i]);
  }
  printf("\n");


  // Decode the entry

  DecodeEd25519Blade2bEntryArgs decode_args = {
    .entry_length = args.out_length,
    .entry_bytes = args.out,
  };

  Error e = decode_ed25519_blake2b_entry(&decode_args);

  if(e != 0){
    printf("error decoding, error code: %i", e);
  }else{
    printf("entry decoded ok!!\n");
    printf("log_id: %li \n", decode_args.out_decoded_entry.log_id);
    printf("seq_num: %li \n", decode_args.out_decoded_entry.seq_num);
    printf("is_end_of_feed: %i \n", decode_args.out_decoded_entry.is_end_of_feed);
    printf("payload_length: %li \n", decode_args.out_decoded_entry.payload_length);
  }

  // Verify the entry
  VerifyEd25519Blake2bEntryArgs verify_args = {
    .payload_bytes = payload,
    .payload_length = PAYLOAD_LENGTH,
    .backlink_bytes = NULL,
    .backlink_length =  0,
    .lipmaalink_bytes = NULL,
    .lipmaalink_length =  0,
    .entry_bytes = out,
    .entry_length = args.out_length,
  };
  
  intptr_t result2 = verify_ed25519_blake2b_entry(&verify_args);

  if(result2 != 0){
    printf("error verifying, error code: %li", result2);
  }else{
    printf("entry is valid!!\n");
  }



}
