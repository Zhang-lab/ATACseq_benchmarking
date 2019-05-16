#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <random>
#include <cmath>
#include <iostream>
#include <string>
#include <ctime>


int main(int argc, char *argv[])
{
    std::default_random_engine generator;
    srand(time(NULL));
    generator.seed(rand());
    //Distributions for 10%, 20% 50% and 100%.
    std::normal_distribution<double> distribution0_0(10.0,1.00);
    std::normal_distribution<double> distribution1_1(9.5,0.95);
    std::normal_distribution<double> distribution1_2(10.5,1.05);
    std::normal_distribution<double> distribution2_1(9.0,0.90);
    std::normal_distribution<double> distribution2_2(11.0,1.10);
    std::normal_distribution<double> distribution3_1(8.0,0.80);
    std::normal_distribution<double> distribution3_2(12.0,1.20);
    std::normal_distribution<double> distribution4_1(6.67,0.667);
    std::normal_distribution<double> distribution4_2(13.33,1.333);
    
    FILE *out;
    
    double number=0.0;
    int val=0;
    
    //Open file and print header line.
    out=fopen(argv[1],"w");
    fprintf(out,"name\tlengt");
    for (int i=0; i<20; i++)
        fprintf(out,"\tc1r%d",i+1);
    for (int i=0; i<20; i++)
        fprintf(out,"\tc2r%d",i+1);
    fprintf(out,"\n");
    
    //Print the pseudo counts table.  For each test, ensure reads aren't negative.
    //Split peaks such that the peaks with the greater number of reads are
    //equally distributed between c1 and c2.  Print 20 values per condition.
    
    for(int i=0; i<154835; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"1CPM_equal_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=distribution0_0(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=distribution0_0(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    
    for(int i=0; i<4839; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"1CPM_10diff_c1up_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=distribution1_2(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=distribution1_1(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    for(int i=0; i<4839; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"1CPM_10diff_c2up_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=distribution1_1(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=distribution1_2(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    
    for(int i=0; i<4839; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"1CPM_20diff_c1up_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=distribution2_2(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=distribution2_1(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    for(int i=0; i<4839; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"1CPM_20diff_c2up_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=distribution2_1(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=distribution2_2(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    
    for(int i=0; i<4839; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"1CPM_50diff_c1up_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=distribution3_2(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=distribution3_1(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    for(int i=0; i<4839; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"1CPM_50diff_c2up_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=distribution3_1(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=distribution3_2(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    
    for(int i=0; i<4839; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"1CPM_100diff_c1up_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=distribution4_2(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=distribution4_1(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    for(int i=0; i<4839; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"1CPM_100diff_c2up_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=distribution4_1(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=distribution4_2(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    
    for(int i=0; i<77418; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"5CPM_equal_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=5.0*distribution0_0(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=5.0*distribution0_0(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    
    for(int i=0; i<2419; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"5CPM_10diff_c1up_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=5.0*distribution1_2(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=5.0*distribution1_1(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    for(int i=0; i<2419; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"5CPM_10diff_c2up_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=5.0*distribution1_1(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=5.0*distribution1_2(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    
    for(int i=0; i<2419; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"5CPM_20diff_c1up_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=5.0*distribution2_2(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=5.0*distribution2_1(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    for(int i=0; i<2419; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"5CPM_20diff_c2up_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=5.0*distribution2_1(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=5.0*distribution2_2(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    
    for(int i=0; i<2419; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"5CPM_50diff_c1up_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=5.0*distribution3_2(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=5.0*distribution3_1(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    for(int i=0; i<2419; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"5CPM_50diff_c2up_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=5.0*distribution3_1(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=5.0*distribution3_2(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    
    for(int i=0; i<2419; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"5CPM_100diff_c1up_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=5.0*distribution4_2(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=5.0*distribution4_1(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    for(int i=0; i<2419; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"5CPM_100diff_c2up_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=5.0*distribution4_1(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=5.0*distribution4_2(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    
    for(int i=0; i<25806; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"10CPM_equal_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=10.0*distribution0_0(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=10.0*distribution0_0(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    
    for(int i=0; i<806; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"10CPM_10diff_c1up_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=10.0*distribution1_2(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=10.0*distribution1_1(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    for(int i=0; i<806; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"10CPM_10diff_c2up_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=10.0*distribution1_1(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=10.0*distribution1_2(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    
    for(int i=0; i<806; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"10CPM_20diff_c1up_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=10.0*distribution2_2(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=10.0*distribution2_1(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    for(int i=0; i<806; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"10CPM_20diff_c2up_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=10.0*distribution2_1(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=10.0*distribution2_2(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    
    for(int i=0; i<806; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"10CPM_50diff_c1up_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=10.0*distribution3_2(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=10.0*distribution3_1(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    for(int i=0; i<806; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"10CPM_50diff_c2up_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=10.0*distribution3_1(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=10.0*distribution3_2(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    
    for(int i=0; i<806; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"10CPM_100diff_c1up_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=10.0*distribution4_2(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=10.0*distribution4_1(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    for(int i=0; i<806; i++)
    {
        //Give peak name CPM and difference between up/down info and the number.
        fprintf(out,"10CPM_100diff_c2up_%d\t100",i+1);
        //Now get the values and print them.
        for(int j=0; j<20; j++)
        {
            number=10.0*distribution4_1(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        for(int j=0; j<20; j++)
        {
            number=10.0*distribution4_2(generator);
            val=round(number);
            if (val<0)
                val=0;
            fprintf(out,"\t%d",val);
        }
        fprintf(out,"\n");
    }
    
    fclose(out);
    return 0;
    
    
}
