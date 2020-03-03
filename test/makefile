.PHONY: $(OBJDIR)/string_util_ut

all-ut: $(OBJDIR)/string_util_ut

$(OBJDIR)/string_util_ut.o: $(TESTDIR)/string_util_ut.c
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJDIR)/string_util_ut: $(OBJDIR)/string_util_ut.o \
    	$(OBJDIR)/string_util.o $(OBJDIR)/ctest_main.a
	$(CC) $(CFLAGS) -lpthread $^ -o $@
	./$(OBJDIR)/string_util_ut
