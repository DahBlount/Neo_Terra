// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * Here's where we create all of our CFG reading stuff
 */

struct RECIPE
{
	RECIPE() : producedItem(), cookingRate(0) {}
	FName nickname;
	FName producedItem;
	FString infotext;
	unsigned int cookingRate;
	TMap < FName, unsigned int > consumed_items;
};

extern TMap<FName, RECIPE> RecipeMap;

class FileRead
{
public:
	FileRead(class FileRead const &);
	FileRead(void);
	~FileRead();
	class FileRead & operator=(class FileRead const &);
	void close(void);
	bool find_header(TCHAR *);
	bool get_bool(unsigned int);
	FName * get_file_name(void);
	FName * get_header_ptr(void);
	TCHAR * get_indexed_value(unsigned int);
	int get_line_num(void)const;
	TCHAR * get_line_ptr(void);
	TCHAR * get_name(void)const;
	TCHAR * get_name_ptr(void);
	unsigned int get_num_parameters(void)const;
	// void get_state(struct State &)const;
	bool get_value_bool(unsigned int);
	float get_value_float(unsigned int);
	int get_value_int(unsigned int);
	TCHAR * get_value_ptr(void);
	TCHAR * get_value_string(unsigned int);
	TCHAR * get_value_string(void);
	unsigned short const * get_value_wstring(void);
	class FVector  get_vector(void);
	bool is_end(void)const;
	bool is_header(TCHAR *);
	bool is_number(TCHAR *)const;
	bool is_value(TCHAR *);
	bool is_value_empty(unsigned int);
	void log_link(TCHAR *);
	bool open(TCHAR *, bool);
	// bool open_memory(TCHAR *, unsigned int);
	bool read_header(void);
	bool read_value(void);
	void reset(void);
	void seek(unsigned int);
	// void set_state(struct State const &);
	unsigned int tell(void)const;
	double value_num(unsigned int);

public:
	TCHAR data[5480];
};