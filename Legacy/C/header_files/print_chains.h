void print_chains (double free_particle[n_max][m_max][z_max],
                   double image_free_particle[n_max][m_max][z_max],
                   double wall_particle[44][m_max][z_max],
                   double free_forces[n_max][n_max][z_max],
                   double image_free_forces[n_max][n_max][z_max],
                   double wall_free_forces[n_max][44][z_max])
{
     char func_name[30] = "print_chains";
     char action_begin[10] = ">>>";
     char action_end[10] = "<<<";
     time_stamp();
     trace(func_name,action_begin);
       for(i = 0; i < n_max; i++)
        {
         for(j = 0; j < n_max; j++)
          {
           fprintf(fptr30,"%lf\t%lf\t%lf\t%lf\t%lf\n",free_particle[i][2][1],free_particle[j][2][1],
                                        free_particle[i][3][1],free_particle[j][3][1],
                                        (fabs(free_forces[i][j][0]+free_forces[i][j][1])));
                                        
           fprintf(fptr31,"%lf\t%lf\t%lf\t%lf\t%lf\n",free_particle[i][2][1],image_free_particle[j][2][0],
                                        free_particle[i][3][1],image_free_particle[j][3][0],
                                        (fabs(image_free_forces[i][j][0]+image_free_forces[i][j][1])));
          }
        }
        fprintf(fptr30,"\n");
        fprintf(fptr31,"\n");
        
        for(i = 0; i < n_max; i++)
         {
          for(j = 0; j < 44; j++)
           {
            fprintf(fptr32,"%lf\t%lf\t%lf\t%lf\t%lf\n",free_particle[i][2][1],wall_particle[j][2][0],
                                        free_particle[i][3][1],wall_particle[j][3][0],
                                        (fabs(wall_free_forces[i][j][0]+wall_free_forces[i][j][1])));    
           }
         }
         fprintf(fptr32,"\n");
     time_stamp();
     trace(func_name,action_end);
}
