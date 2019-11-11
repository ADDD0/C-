#include "gene.h"
#include <string.h>
#include <iostream>

using namespace std;

int main() {
    Gene *gene=new Gene;

    int gen = 0;
    int oldMaxPop;
    double oldMax;

    srand((unsigned)time(NULL));
    gene->initPop();
    memcpy(&gene->newPop, &gene->oldPop, POP_SIZE * sizeof(struct Gene::population));
    gene->statistics(gene->newPop);  //计算种群的最大适应度和最小适应度以及适应度的下标号
    gene->report(gene->newPop, gen);

    while (gen < CENERAION_NUM) {
        gen += 1;
        if (gen % 100 == 0)
            srand((unsigned)time(NULL));
        oldMax = gene->maxFitness;   //oldmax为种群中最大适应度
        oldMaxPop = gene->maxPop;    //oldMaxPop指种群中最大适应度的个体
        gene->generation();
        gene->statistics(gene->newPop);

        if (gene->maxFitness < oldMax) {
            for (int k=0; k < CHROM_SIZE; ++k)
                gene->newPop[gene->minPop].chrom[k] = gene->oldPop[oldMaxPop].chrom[k];
            gene->newPop[gene->minPop].fitness = gene->oldPop[oldMaxPop].fitness;
            gene->newPop[gene->minPop].weight = gene->oldPop[oldMaxPop].weight;
            gene->newPop[gene->minPop].volume = gene->oldPop[oldMaxPop].volume;
            gene->newPop[gene->minPop].parent1 = gene->oldPop[oldMaxPop].parent1;
            gene->newPop[gene->minPop].parent2 = gene->oldPop[oldMaxPop].parent2;
            gene->newPop[gene->minPop].cross = gene->oldPop[oldMaxPop].cross;
            gene->statistics(gene->newPop);
        } else if(gene->maxFitness > oldMax)
            gene->report(gene->newPop, gen);
        memcpy(&gene->oldPop, &gene->newPop, POP_SIZE * sizeof(struct Gene::population));
    }

    delete[] gene;  //销毁对象占用空间
    return 0;
}