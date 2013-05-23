double packing_density (double free_particle[n_max][m_max][z_max],
                        double wall_particle[44][m_max][z_max])
{
 double sum1,sum2,width,height,ans;

     sum1 = 0.0;
     sum2 = 0.0;
     width = 10.0;
     height = ((wall_particle[28][3][0]) - (wall_particle[6][3][0]));
     char func_name[30] = "packing_density";
     char action_begin[10] = ">>>";
     char action_end[10] = "<<<";
     time_stamp();
     trace(func_name,action_begin);
 
 for(i = 0; i < n_max; i++)
  {
   sum1 += (pow((free_particle[i][9][0]),2.0))*PI;
  }
  
  sum2 = width*(PI*(pow(0.5,2.0)));
 
  ans = ((sum1+sum2)/(width*height));
  
  return(ans);
  time_stamp();
  trace(func_name,action_end);
}
