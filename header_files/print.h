void print(double free_particle[n_max][m_max][z_max],double packing)
{
    char func_name[30] = "print";
    char action_begin[10] = ">>>";
    char action_end[10] = "<<<";
    time_stamp();
    trace(func_name,action_begin);  
    for(i = 0; i < n_max; i++)
     {
     /*Print Positions and Velocities to file 'positions.dat' and 'velocities.dat'*/
      fprintf(fptr1,"%lf\t%lf\t",free_particle[i][2][1],free_particle[i][3][1]);
      fprintf(fptr10,"%lf\t%lf\t",image_free_particle[i][2][1],image_free_particle[i][3][1]);
     }
    fprintf(fptr1,"\n");
    fprintf(fptr10,"\n");
  
    for(i = 0; i < 44; i++)
     {
     /*Print the positions of the wall particles to file 'wall_positions.dat'*/
     fprintf(fptr9,"%lf\t%lf\t",wall_particle[i][2][0],wall_particle[i][3][0]);
     }
    fprintf(fptr9,"\n");
    time_stamp();
    trace(func_name,action_end);
}
