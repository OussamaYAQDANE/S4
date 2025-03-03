#include <iostream>
#include <memory>

struct MemoryBlock {
    int size;

    MemoryBlock(int s) : size(s) {}
};

std::unique_ptr<MemoryBlock> allocate(int s) {
    std::cout << "Bloc de mémoire alloué de " << s << " unités." << std::endl;
    return std::make_unique<MemoryBlock>(s);
}

std::unique_ptr<MemoryBlock> mergeBlocks(std::unique_ptr<MemoryBlock> b1, std::unique_ptr<MemoryBlock> b2) {
    int mergedSize = b1->size + b2->size;
    std::cout << "Fusion des deux blocs : " << mergedSize << " unités." << std::endl;
    return std::make_unique<MemoryBlock>(mergedSize);
}

int main() {
    auto block1 = allocate(100);
    auto block2 = allocate(200);

    auto mergedBlock = mergeBlocks(std::move(block1), std::move(block2));

    mergedBlock.reset(); 
    std::cout << "Libération de la mémoire." << std::endl;
}
