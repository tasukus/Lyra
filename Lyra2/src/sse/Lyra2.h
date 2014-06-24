/**
 * Header file for the Lyra2 Password Hashing Scheme (PHS). SSE-oriented implementation.
 * 
 * Author: The Lyra PHC team (http://www.lyra-kdf.net/) -- 2014.
 * 
 * This software is hereby placed in the public domain.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ''AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef LYRA2_H_
#define LYRA2_H_

typedef unsigned char byte ;

//Block length required so Blake2's Initialization Vector (IV) is not overwritten (THIS SHOULD NOT BE MODIFIED)
#define BLOCK_LEN_BLAKE2_SAFE_INT64 8                                   //512 bits (=64 bytes, =8 uint64_t)
#define BLOCK_LEN_BLAKE2_SAFE_BYTES (BLOCK_LEN_BLAKE2_SAFE_INT64 * 8)   //same as above, in bytes

#define BLOCK_LEN_INT64 12                               //Block length: 768 bits (=96 bytes, =12 uint64_t)
#define BLOCK_LEN_BYTES (BLOCK_LEN_INT64 * 8)           //Block length, in bytes

#ifndef N_COLS
#define N_COLS 64                                       //Number of columns in the memory matrix: fixed to 64 by default
#endif

#define ROW_LEN_INT64 (BLOCK_LEN_INT64 * N_COLS)        //Total length of a row: N_COLS blocks
#define ROW_LEN_BYTES (ROW_LEN_INT64 * 8)               //Number of bytes per row

#define BLOCK_LEN_INT128 BLOCK_LEN_INT64/2             //Block lenght: 512 bits (=64 bytes, =4 __m128i)
#define ROW_LEN_INT128 (ROW_LEN_INT64/2)      //Total length of a row: N_COLS blocks

#ifndef N_COLS
#define N_COLS 64                                       //Number of columns in the memory matrix: fixed to 64
#endif

int LYRA2(void *K, unsigned int kLen, const void *pwd, unsigned int pwdlen, const void *salt, unsigned int saltlen, unsigned int t_cost, unsigned int m_cost);

int PHS(void *out, size_t outlen, const void *in, size_t inlen, const void *salt, size_t saltlen, unsigned int t_cost, unsigned int m_cost);

#endif /* LYRA2_H_ */
