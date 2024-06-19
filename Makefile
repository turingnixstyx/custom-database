BUILD_DIR = build

all: $(BUILD_DIR)
	cd $(BUILD_DIR) && $(MAKE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake ..

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean all

run: all
	./$(BUILD_DIR)/my_cpp_database