#Tests for simulated ATAC normalization for edgeR
suppressMessages(library(edgeR))
suppressMessages(library(stringr))
args <- commandArgs(trailingOnly = TRUE)

simulated_data_20_reps <- read.table(args[1],sep="\t",header = TRUE)
rownames(simulated_data_20_reps) <- simulated_data_20_reps[,1]
lengths <- simulated_data_20_reps[,2]
simulated_data_20_reps<-simulated_data_20_reps[,-(1:2)]
colData20 <- as.data.frame(read.table(args[2],sep = "\t", header = TRUE))
rownames(colData20) <- colData20[,1]
colData20 <- colData20[-1]
results <- as.data.frame(c(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0))
rownames(results) <- c("1CPM_equal","1CPM_10diff","1CPM_20diff","1CPM_50diff","1CPM_100diff","5CPM_equal","5CPM_10diff","5CPM_20diff","5CPM_50diff","5CPM_100diff","10CPM_equal","10CPM_10diff","10CPM_20diff","10CPM_50diff","10CPM_100diff")
colnames(results) <-"values"
for (i in c(20,15,12,10,8,6,5,4,3,2))
{
  cat("\nProcessing ",basename(args[1])," with ",i," reps.\n")
  mydata <- as.matrix(simulated_data_20_reps[,c(1:i,21:(20+i))])
  mycoldata <- as.data.frame(colData20[c(1:i,21:(20+i)),])
  rownames(mycoldata) <- rownames(colData20)[c(1:i,21:(20+i))]
  colnames(mycoldata) <- "condition"
  mydata <- cpm(mydata)
  mylog2data <- cpm(mydata,log = TRUE, prior.count = 0.001)
  mypvals <- apply(mydata, 1, function(mydata) {
    t.test(x = mydata[1:i], y = mydata[(i + 1):(2*i)],alternative = "two.sided")$p.value})
  mylog2pvals <- apply(mylog2data, 1, function(mylog2data) {
    t.test(x = mylog2data[1:i], y = mylog2data[(i + 1):(2*i)],alternative = "two.sided")$p.value})
  mypadj <- p.adjust(mypvals, method = 'BH')
  mylog2padj <- p.adjust(mylog2pvals, method = 'BH')
  myresults<-as.data.frame(mydata)
  mylog2results<-as.data.frame(mylog2data)
  myresults$padj <- mypadj
  mylog2results$padj <-mylog2padj
  myresults <- myresults[myresults$padj < 0.05,]
  mylog2results <- mylog2results[mylog2results$padj < 0.05,]
  rowvals<-rownames(myresults)
  log2rowvals <- rownames(mylog2results)
  for (j in c(1:15))
  {
    results$values[j] <-sum(str_count(rowvals,rownames(results)[j]))
    
  }
  write.table(results,file=paste("cpm_t_test_",basename(args[1]),"_",i,"_reps.txt",sep = ""),quote = FALSE, sep = )
  for (j in c(1:15))
  {
    results$values[j] <-sum(str_count(log2rowvals,rownames(results)[j]))
    
  }
  write.table(results,file=paste("log2_cpm_t_test_",basename(args[1]),"_",i,"_reps.txt",sep = ""),quote = FALSE, sep = )
}