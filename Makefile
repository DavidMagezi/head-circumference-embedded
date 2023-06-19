#change DLIB_DIR to where you downloaded d-lib
LOCAL_DIR = /home/$(USER)/local
DLIB_DIR = $(LOCAL_DIR)/dlib/source/dlib-19.24
ULTRASOUND_DIR = $(LOCAL_DIR)/ultrasound/

CXX = g++
CFLAGS = -O3 -lpthread -lX11 -std=c++17 -I$(DLIB_DIR) -DDLIB_PNG_SUPPORT -lpng
OBJ_EXT = .o
CPP_EXT =.cpp

BASE_DIR = ./
EXEC_DIR = $(BASE_DIR)bin
SRC_DIR = $(BASE_DIR)src
OBJ_DIR =$(BASE_DIR)objs

DLIB_SRC=$(DLIB_DIR)/dlib/all/source

TARGET_STEM = head_circumference
TARGET = $(EXEC_DIR)/$(TARGET_STEM)

_ML = machine_learning
_ML_DEPS = logger.h image.h

ML_OBJ_DIR = $(OBJ_DIR)/$(_ML)
ML_SRC_DIR = $(SRC_DIR)/$(_ML)
ML_DEPS = $(addprefix $(ML_SRC_DIR)/, $(_ML_DEPS))
_ML_OBJS = $(_ML_DEPS:.h=.o) 
ML_OBJS = $(addprefix $(ML_OBJ_DIR)/, $(_ML_OBJS))

_AGS = active_geometric_shape
_AGS_DEPS = ellipse.h 

AGS_OBJ_DIR = $(OBJ_DIR)/$(_AGS)
AGS_SRC_DIR = $(SRC_DIR)/$(_AGS)
AGS_DEPS = $(addprefix $(AGS_SRC_DIR)/, $(_AGS_DEPS))
_AGS_OBJS = $(_AGS_DEPS:.h=.o) 
AGS_OBJS = $(addprefix $(AGS_OBJ_DIR)/, $(_AGS_OBJS))

all: $(TARGET)
	@echo "DLIB is $(DLIB_DIR)"
	@echo "DLIB_SRC is $(DLIB_SRC)"

$(EXEC_DIR):
	mkdir -p $@

$(ML_OBJ_DIR):
	mkdir -p $@

$(ML_OBJS): $(ML_OBJ_DIR)/%$(OBJ_EXT): $(ML_SRC_DIR)/%$(CPP_EXT) $(DLIB_SRC)$(CPP_EXT) $(ML_DEPS) | $(ML_OBJ_DIR)
	$(CXX)  $< -c -o $@  $(CFLAGS) -iquote$(ML_SRC_DIR) 

$(AGS_OBJ_DIR):
	mkdir -p $@

$(AGS_OBJS): $(AGS_OBJ_DIR)/%$(OBJ_EXT): $(AGS_SRC_DIR)/%$(CPP_EXT) $(DLIB_SRC)$(CPP_EXT) $(AGS_DEPS) | $(AGS_OBJ_DIR)
	$(CXX)  $< -c -o $@  $(CFLAGS) -iquote$(AGS_SRC_DIR) 

$(TARGET): $(SRC_DIR)/$(TARGET_STEM)$(CPP_EXT) $(DLIB_SRC)$(CPP_EXT) $(ML_OBJS) | $(EXEC_DIR)
	@echo "Building $(TARGET) ..."
	$(CXX) $< -o $@ $(DLIB_SRC)$(CPP_EXT) $(ML_OBJS) $(CFLAGS)

clean:
	rm $(TARGET) $(ML_OBJS)
	rmdir $(EXEC_DIR) $(ML_OBJ_DIR) $(OBJ_DIR)

run:
	@echo "ULTRASOUND directory is $(ULTRASOUND_DIR)"
	$(TARGET) $(ULTRASOUND_DIR)

