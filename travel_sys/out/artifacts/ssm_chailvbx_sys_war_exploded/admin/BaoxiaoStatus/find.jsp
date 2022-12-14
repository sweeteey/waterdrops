<%@ page language="java" contentType="text/html; charset=UTF-8"    
	pageEncoding="UTF-8"%>                                               
<%                                                                        
	String path = request.getContextPath();                                 
	String basePath = request.getScheme() + "://"                         
			+ request.getServerName() + ":" + request.getServerPort()         
			+ path + "/";                                                     
%>                                                                        
<%@ include file="/common/css.jsp"%>                                    
<%@ include file="/common/js.jsp"%>                                     
<%@ include file="/common/taglib.jsp"%>                                 
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">         
<html>                                                                    
<head>                                                                    
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">   
<base href="<%=basePath%>">                                             
<title><spring:message code="system_name" /></title>                    
<script type="text/javascript">                                         
	function topPage() {                                                    
                                                                          
		var contextPath = "${pageContext.request.contextPath}";             
		var field = document.getElementById("field").value;                 
		var fieldValue = document.getElementById("fieldValue").value;       
		var pageNo = "${pageModel.topPageNo}";                              
		window.location = contextPath                                         
				+ '/BaoxiaoStatus/getAllUtil.do?pageModel.currentPageNo=' + pageNo     
				+ '&field=' + field + '&fieldValue=' + fieldValue + '';           
	}                                                                       
                                                                          
	function previousPage() {                                               
		var contextPath = "${pageContext.request.contextPath}";             
		var field = document.getElementById("field").value;                 
		var fieldValue = document.getElementById("fieldValue").value;       
		var pageNo = "${pageModel.previousPageNo}";                         
		window.location = contextPath                                         
				+ '/BaoxiaoStatus/getAllUtil.do?pageModel.currentPageNo=' + pageNo     
				+ '&field=' + field + '&fieldValue=' + fieldValue + '';           
	}                                                                       
                                                                          
	function nextPage() {                                                   
                                                                          
		var contextPath = "${pageContext.request.contextPath}";             
		var field = document.getElementById("field").value;                 
		var fieldValue = document.getElementById("fieldValue").value;       
		var pageNo = "${pageModel.nextPageNo}";                             
		window.location = contextPath                                         
				+ '/BaoxiaoStatus/getAllUtil.do?pageModel.currentPageNo=' + pageNo     
				+ '&field=' + field + '&fieldValue=' + fieldValue + '';           
	}                                                                       
                                                                          
	function bottomPage() {                                                 
		var contextPath = "${pageContext.request.contextPath}";             
		var field = document.getElementById("field").value;                 
		var fieldValue = document.getElementById("fieldValue").value;       
		var pageNo = "${pageModel.buttomPageNo}";                           
		window.location = contextPath                                         
				+ '/BaoxiaoStatus/getAllUtil.do?pageModel.currentPageNo=' + pageNo     
				+ '&field=' + field + '&fieldValue=' + fieldValue + '';           
	}                                                                       
                                                                          
	function datadel() {                                                    
                                                                          
		var ids = document.getElementsByName("id");                         
		var flag = 0;                                                         
		for ( var i = 0; i < ids.length; i++) {                               
			if (ids[i].checked) {                                               
				flag = 1;                                                         
				break;                                                            
			}                                                                   
		}                                                                     
		if (flag == 1) {                                                      
			if(confirm("??????????????????")){                                           
				document.myform.submit();                                           
			}else{                                           
			return false;                                           
			}                                           
		} else {                                                              
			alert("????????????????????????");                                             
			return false;                                                       
		}                                                                     
                                                                          
	}                                                                       
</script>                                                                 
</head>                                                                   
<body class="pos-r">                                                                  
	<div>                                                                                 
		<nav class="breadcrumb"> <i class="Hui-iconfont">&#xe67f;</i> ??????              
		<span class="c-gray en">&gt;</span>?????????????????? <span class="c-gray en">&gt;</span>
		???????????????????????? <a class="btn btn-success radius r"                                      
			style="line-height:1.6em;margin-top:3px"                                        
			href="javascript:location.replace(location.href);" title="??????"><i            
			class="Hui-iconfont">&#xe68f;</i> </a> </nav>                                   
		<div class="page-container">                                                      
			<div class="text-c">                                                            
				<form                                                                           
					action="${pageContext.request.contextPath}/BaoxiaoStatus/getAllUtil.do">    
					<select id="field" name="field" class="select"
						style="width:120px;height:32px;">

						<option <c:if test="${field == 's_0'}">selected</c:if> value="s_0" />
							??????
						</option>					</select>
					 <input type="text" name="fieldValue" id="fieldValue"                              
						value="${fieldValue }" placeholder=" ????????????" style="width:250px"                        
						class="input-text">                                                                           
					<button name="" id="" class="btn btn-success" type="submit">                              
						<i class="Hui-iconfont">&#xe665;</i> ??????                                                     
					</button>                                                                                         
					&nbsp;&nbsp; <input class="btn btn-success" type="button"                                     
						value="??????"                                                                                  
						onclick="javascript: document.getElementById('fieldValue').value='';" />                      
					&nbsp;&nbsp;                                                                                      
				</form>                                                                                             
			</div>                                                                                                
			<div class="cl pd-5 bg-1 bk-gray mt-20">                                                            
				<span class="l">
			<c:if test="${user_type == 'admin'}"><a href="javascript:;" onclick="datadel()"                                    
					class="btn btn-danger radius"><i class="Hui-iconfont">&#xe6e2;</i>                            
						????????????</a> 
			</c:if>
			<c:if test="${user_type == type1 || user_type == type2 }">
			<a class="btn btn-primary radius" style="margin-left:20px;"                    
					href="${pageContext.request.contextPath}/BaoxiaoStatus/initUtil.do"><i                   
						class="Hui-iconfont">&#xe600;</i> ??????</a> 
			</c:if></span> <span class="r">????????????<strong></strong>
				</span>                                                                                             
			</div>                                                                                                
			<div class="mt-20">                                                                                 
				<form                                                                                               
					action="${pageContext.request.contextPath}/BaoxiaoStatus/deleteManyUtil.do"                     
					name="myform" id="myform" method="post">                                                    
					<table                                                                                            
						class="table table-border table-bordered table-bg table-hover table-sort">                    
						<thead>                                                                                         
							<tr class="text-c">                                                                         
								<th width="60"><input name="" type="checkbox" value="">&nbsp;??????                   
								</th>                                                                                       
								<th>??????</th>
								<th>??????</th>
							</tr>
						</thead>
						<tbody>
							<c:if test="${fn:length(pageModel.list) < 1}">
								<tr class="text-c va-m">                    
									<td colspan=12>?????????</td>                   
								</tr>                                         
							</c:if>                                         

							<c:forEach var="tmp" items="${pageModel.list}">
								<tr class="text-c">
									<td><input name="id" value="${tmp.id }" type="checkbox">
									</td>                                                         
									<td>${tmp.s_0 }</td>

								<c:if test="${user_type == 'admin'}">
									<td class="td-manage"><a style="text-decoration:none;margin-left:15px;"                                   
										class="ml-5"                                                                            
										href="${pageContext.request.contextPath}/BaoxiaoStatus/selectUtil.do?id=${tmp.id }"
										title="??????"><i class="Hui-iconfont">&#xe6df;</i> ??????</a> <a                             
										style="text-decoration:none;margin-left:15px;" class="ml-5"                           
										href="${pageContext.request.contextPath}/BaoxiaoStatus/deleteUtil.do?id=${tmp.id }"
										title="??????"><i class="Hui-iconfont">&#xe6e2;</i>?????? </a>                                
									</td>                                                                                       

								</c:if>

								<c:if test="${user_type != 'admin'}">
									<td class="td-manage"><a style="text-decoration:none;margin-left:15px;"                                   
										class="ml-5"                                                                            
										href="${pageContext.request.contextPath}/BaoxiaoStatus/selectUtil.do?id=${tmp.id }"
										title="??????"><i class="Hui-iconfont">&#xe6df;</i>?????? </a>                                
									</td>                                                                                       

								</c:if>

						</tr>
					</c:forEach>
				</tbody>
			</table>
		</form>
		<br />
		<table width="90%" height="30" border="0" align="center"
			cellpadding="0" cellspacing="0" class="rd1">
			<tr>
				<td nowrap class="rd19" height="2" width="36%">
					<div align="left">
						<font>&nbsp;???&nbsp;${pageModel.totalRecords}&nbsp;???</font>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
						<font>?????????</font>&nbsp; <font color="#FF0000">${pageModel.currentPageNo}</font>&nbsp;/&nbsp;${pageModel.totalPages}
						<font>???</font>
					</div>
				</td>
				<td nowrap class="rd19" width="64%">
					<div align="right">
						<input name="btnTopPage" class="btn btn-inverse" type="button"
							id="btnTopPage" value="|&lt;&lt; " title="??????"
							onClick="javascript:topPage();">
						<input name="btnPreviousPage" class="btn btn-inverse" type="button"
							id="btnPreviousPage" value=" &lt;  " title="??????"
							onClick="javascript:previousPage();">
						<input name="btnNextPage" class="btn btn-inverse" type="button"
							id="btnNextPage" value="  &gt; " title="??????" onClick="javascript:nextPage();">
						<input name="btnBottomPage" class="btn btn-inverse" type="button"
							id="btnBottomPage" value=" &gt;&gt;|" title="??????"
							onClick="javascript:bottomPage();">
					</div>
				</td>
			</tr>
		</table>
	</body>
</html>
