void *time_stamp( );
void trace( char func_name[], char action[] );

void *time_stamp( ){
	char *timestamp = (char *)malloc(sizeof(char) * 16);
	time_t ltime;
	ltime=time(NULL);
	struct tm *tm;
	tm=localtime(&ltime);

	fprintf(fptr_trace,"%04d%02d%02d%02d%02d%02d, ", 
                 tm->tm_year+1900,
                 tm->tm_mon,
                 tm->tm_mday,
                 tm->tm_hour,
                 tm->tm_min,
                 tm->tm_sec);
}

void trace( char func_name[], char action[] ){
        fprintf(fptr_trace,"%s %s \n",
                &func_name[0],
                &action[0]);
}
/*EOF*/
