#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct page {
	int num;
	uint16_t priority;
};

int find_page(struct page *pages, int page_cnt, int num) {
	int i;
	for (i = 0; i < page_cnt; i++) {
		if (pages[i].num == num) {
			break;
		}
	}

	return i;
}

int main(int argc, char *argv[]) {
	int page_cnt = argc > 1 ? atoi(argv[1]) : 10;
	struct page *pages = malloc(page_cnt * sizeof(struct page));

	for (int i = 0; i < page_cnt; i++) {
		pages[i].num = -1;
		pages[i].priority = 0;
	}

	FILE *file;
	file = fopen("Lab 09 input.txt", "r");

	int hit_cnt = 0;
	int miss_cnt = 0;

	int page_num;
	int free_pages = page_cnt;
	while(fscanf(file, "%d", &page_num) != EOF) {
		for (int i = 0; i < page_cnt; i++) {
			pages[i].priority >>= 1;
		}

		int page_pos = find_page(pages, page_cnt, page_num);

		if (page_pos != page_cnt) {
			hit_cnt++;
		} else {
			if (free_pages != 0) {
				pages[--free_pages].num = page_num;
				page_pos = free_pages;
			} else {
				uint16_t min_priority = pages[0].priority;
				page_pos = 0;

				for (int i = 0; i < page_cnt; i++) {
					if (min_priority >= pages[i].priority) {
						min_priority = pages[i].priority;
						page_pos = i;
					}
				}

				pages[page_pos].num = page_num;
				pages[page_pos].priority = 0;
			}

			miss_cnt++;
		}
		pages[page_pos].priority |= (1 << 15);

		for (int i = 0; i < page_cnt; i++) {
			printf("i = %d id = %d %d\n", i, pages[i].num, pages[i].priority);
		}
		printf("current page number %d\n", page_num);
		printf("\n");
	}

	printf("hit = %f miss = %f ratio = %f\n", (double) hit_cnt, (double) miss_cnt, (double) hit_cnt / miss_cnt);

	free(pages);
	return 0;
}
