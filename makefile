ifneq ($(MAKECMDGOALS), clean)
goals = $(MAKECMDGOALS)
endif
	
$(goals): $(addsuffix .c, $(goals))
	gcc $^ -o $@ -lGL -lGLU -lglut 
	$(addprefix  ./, $(goals))	
clean:
	rm $(patsubst %.c, %, $(wildcard *.c))

