<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
		<title>无标题文档</title>
		<%@ include file="../com.jsp"%>
		<link href="${pageContext.request.contextPath}/common/css/style.css" rel="stylesheet"
			type="text/css" />
		<script type="text/javascript" src="${pageContext.request.contextPath}/common/js/jquery.js"></script>
		<script type="text/javascript" src="${pageContext.request.contextPath}/common/js/jsapi.js"></script>
		<script type="text/javascript"
			src="${pageContext.request.contextPath}/common/js/format+zh_CN,default,corechart.I.js"></script>
		<script type="text/javascript"
			src="${pageContext.request.contextPath}/common/js/jquery.gvChart-1.0.1.min.js"></script>
		<script type="text/javascript"
			src="${pageContext.request.contextPath}/common/js/jquery.ba-resize.min.js"></script>

		<script type="text/javascript">
		gvChartInit();
		jQuery(document).ready(function(){

		jQuery('#myTable5').gvChart({
				chartType: 'PieChart',
				gvSettings: {
					vAxis: {title: 'No of players'},
					hAxis: {title: 'Month'},
					width: 650,
					height: 250
					}
			});
		});
		</script>
	</head>


	<body>

		<table id='myTable5'>
			<caption>
				销售统计结果
			</caption>
			<thead>
				<tr>
					<th></th>
					<c:if test="${pageModel.list != 'null'}">
						<c:forEach var="tmp" items="${pageModel.list}">
							<th>
								${tmp.s_0 }
							</th>
						</c:forEach>
					</c:if>
					 
				</tr>
			</thead>
			<tbody>
				<tr>
					<th>

					</th>
					<c:if test="${pageModel.list != 'null'}">
						<c:forEach var="tmp" items="${pageModel.list}">
							<td>
								${tmp.s_2 }
							</td>
						</c:forEach>
					</c:if>
				</tr>
			</tbody>
		</table>


	</body>
	<script type="text/javascript">
		setWidth();
		$(window).resize(function(){
			setWidth();	
		});
		function setWidth(){
			var width = ($('.leftinfos').width()-12)/2;
			$('.infoleft,.inforight').width(width);
		}
	</script>
</html>
