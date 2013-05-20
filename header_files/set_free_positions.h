void set_free_positions(double free_particle[n_max][m_max][z_max])
{
char func_name[35] = "set_free_positions";
char action_begin[10] = ">>>";
char action_end[10] = "<<<";
time_stamp();
trace(func_name,action_begin);
     for(i = 0; i < n_max; i++)
      {
         fscanf(in_fptr1,"%lf\t%lf\n",&free_particle[i][2][0],&free_particle[i][3][0]);
      }
time_stamp();
trace(func_name,action_end);
}
