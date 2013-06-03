<?xml version="1.0"?>
<xsl:stylesheet version="1.0"
                xmlns:html="http://www.w3.org/1999/xhtml"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:import href="wrapstring.xsl"/>

<xsl:output method="text" encoding="UTF-8" indent="no"/>

<xsl:strip-space elements="*"/>



<xsl:variable name="newline">
<xsl:text>
</xsl:text>
</xsl:variable>



<xsl:template match="/">
<xsl:text>-*- buffer-read-only: t -*- vi: set ro:
DO NOT EDIT THIS FILE!  IT IS GENERATED AUTOMATICALLY
from docs/hacking.html.in!



</xsl:text>
<xsl:apply-templates/>
</xsl:template>



<!-- title -->
<xsl:template match="html:h1">
<xsl:text>                         </xsl:text>
<xsl:value-of select="normalize-space(.)"/>
<xsl:text>
                         </xsl:text>======================
</xsl:template>



<!-- output the current text node underlined -->
<xsl:template name="underline">
  <xsl:param name="text" select="normalize-space(.)"/>
  <xsl:param name="text-length" select="string-length($text)"/>
  <xsl:param name="char" select="'='"/>
  <xsl:param name="line" select="$char"/>
  <xsl:choose>
    <xsl:when test="$text-length > 1">
      <xsl:call-template name="underline">
        <xsl:with-param name="text" select="$text"/>
        <xsl:with-param name="text-length" select="$text-length - 1"/>
        <xsl:with-param name="char" select="$char"/>
        <xsl:with-param name="line" select="concat($line,$char)"/>
      </xsl:call-template>
    </xsl:when>
    <xsl:otherwise>
<xsl:value-of select="$text"/>
<xsl:value-of select="$newline"/>
<xsl:value-of select="$line"/>
<xsl:value-of select="$newline"/>
    </xsl:otherwise>
  </xsl:choose>
</xsl:template>



<xsl:template match="html:h2">
<xsl:value-of select="$newline"/>
<xsl:call-template name="underline"/>
</xsl:template>



<xsl:template match="html:h3">
<xsl:call-template name="underline">
<xsl:with-param name="char" select="'-'"/>
</xsl:call-template>
</xsl:template>



<!-- output text line wrapped at 80 chars -->
<xsl:template match="text()">
<xsl:call-template name="wrap-string">
<xsl:with-param name="str" select="normalize-space(.)"/>
<xsl:with-param name="wrap-col" select="80"/>
<xsl:with-param name="break-mark" select="$newline"/>
</xsl:call-template>
</xsl:template>



<xsl:template match="html:ol|html:ul|html:p">
<xsl:apply-templates/><xsl:value-of select="$newline"/><xsl:value-of select="$newline"/>
</xsl:template>



<xsl:template match="html:ol/html:li">
<xsl:choose>
<xsl:when test=".//node()[position()=last()]/self::pre">(<xsl:value-of select="position()"/>) <xsl:apply-templates/>
</xsl:when>
<!-- only append two newlines when the last element isn't a pre element -->
<xsl:otherwise>(<xsl:value-of select="position()"/>) <xsl:apply-templates/><xsl:value-of select="$newline"/><xsl:value-of select="$newline"/>
</xsl:otherwise>
</xsl:choose>
</xsl:template>



<xsl:template match="html:ul/html:li">- <xsl:apply-templates/><xsl:value-of select="$newline"/><xsl:value-of select="$newline"/>
</xsl:template>



<xsl:template match="html:li/html:ul/html:li">-- <xsl:apply-templates/><xsl:value-of select="$newline"/><xsl:value-of select="$newline"/>
</xsl:template>



<!-- add newline before nested <ul> -->
<xsl:template match="html:li/html:ul"><xsl:value-of select="$newline"/><xsl:value-of select="$newline"/><xsl:apply-templates/>
</xsl:template>



<xsl:template match="html:pre">
<xsl:choose>
<xsl:when test="starts-with(.,'&#xA;')"><xsl:value-of select="substring(.,2)"/><xsl:value-of select="$newline"/>
</xsl:when>
<xsl:otherwise>
<xsl:value-of select="."/><xsl:value-of select="$newline"/>
</xsl:otherwise>
</xsl:choose>
</xsl:template>



<xsl:template match="html:a">
<xsl:value-of select="$newline"/><xsl:value-of select="$newline"/>
<xsl:text>  </xsl:text><xsl:apply-templates/>
<xsl:value-of select="$newline"/>
<xsl:text>  </xsl:text><xsl:value-of select="@href"/>
</xsl:template>

</xsl:stylesheet>
