/*

Copyright © 2019 University of California, Berkeley

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

word_count provides lists of words and associated count

Functional methods take the head of a list as first arg.
Mutators take a reference to a list as first arg.
*/

#include "word_count.h"

/* Basic utililties */

char *new_string(char *str) {
  return strcpy((char *)malloc(strlen(str)+1), str);
}

void init_words(WordCount **wclist) {
  /* Initialize word count.  */
  *wclist = NULL;
}

size_t len_words(WordCount *wchead) {
    size_t len = 0;
    WordCount *wc_ptr = wchead;
    while(wc_ptr != NULL){
      wc_ptr = wc_ptr->next;
      len++;
    }
    return len;
}

WordCount *find_word(WordCount *wchead, char *word) {
  /* Return count for word, if it exists */
  WordCount *wc = NULL;
  WordCount *wc_ptr = wchead;
  while(wc_ptr != NULL){
    if(strcmp(wc_ptr->word, word) == 0){
      wc = wc_ptr;
      break;
    }
    wc_ptr = wc_ptr->next;
  }
  return wc;
}

void add_word(WordCount **wclist, char *word) {
  /* If word is present in word_counts list, increment the count, otw insert with count 1. */
  if(*wclist == NULL){
    *wclist = (WordCount*) malloc(sizeof(WordCount));
    (*wclist)->word = word;
    (*wclist)->count = 1;
    (*wclist)->next = NULL;
    return;
  }
  WordCount *target_ptr = find_word(*wclist, word);
  if(target_ptr != NULL){
    target_ptr->count++;
  }else{// insert linknode at tail
    WordCount *dummy_ptr = (WordCount*) malloc(sizeof(WordCount));
    dummy_ptr->word = NULL;
    dummy_ptr->count = 0;
    dummy_ptr->next = NULL;
    dummy_ptr->next = *wclist;
    WordCount *wc_ptr = dummy_ptr;
    while(wc_ptr->next != NULL){
      wc_ptr = wc_ptr->next;
    }
    WordCount *target_ptr = (WordCount*) malloc(sizeof(WordCount));
    target_ptr->word = word;
    target_ptr->count = 1;
    target_ptr->next = NULL;
    wc_ptr->next = target_ptr;
  }
}

void fprint_words(WordCount *wchead, FILE *ofile) {
  /* print word counts to a file */
  WordCount *wc;
  for (wc = wchead; wc; wc = wc->next) {
    fprintf(ofile, "%i\t%s\n", wc->count, wc->word);
  }
}
